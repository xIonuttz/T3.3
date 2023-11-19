#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Define a class for Student
class Student {
public:
    // Constructor
    Student(string name, int age, double gpa)
        : name_(std::move(name)), age_(age), gpa_(gpa) {}

    // Getter functions
    string getName() const {
        return name_;
    }

    int getAge() const {
        return age_;
    }

    double getGPA() const {
        return gpa_;
    }

private:
    string name_;
    int age_;
    double gpa_;
};

int main() {
    // Create a vector of Student objects
    vector<Student> students = {
        {"Alexandra", 20, 3.8},
        {"Bogdan", 22, 3.5},
        {"Florin", 21, 4.0},
        // Add more students as needed
    };

    // Define a student to search for
    Student targetStudent("Bob", 22, 3.5);

    // Search for the student in the vector using std::find_if and a lambda expression
    auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
        // Compare students based on name, age, and GPA
        return student.getName() == targetStudent.getName() &&
            student.getAge() == targetStudent.getAge() &&
            student.getGPA() == targetStudent.getGPA();
        });

    // Check if the student is found
    if (it != students.end()) {
        cout << "Student found:\n";
        cout << "Name: " << it->getName() << ", Age: " << it->getAge() << ", GPA: " << it->getGPA() << "\n";
    }
    else {
       cout << "Student not found.\n";
    }

    return 0;
}
