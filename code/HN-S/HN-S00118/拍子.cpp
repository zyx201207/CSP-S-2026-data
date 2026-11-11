#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    string name;
    cin >> n >> name;
    assert(system(("g++ " + name + ".cpp -o " + name + " -std=c++14 -O2 -Wall -Wextra -fsanitize=address,undefined").c_str()) == 0);
    for(int i = 1; i <= n; i++) {
        system(("cp " + name + to_string(i) + ".in " + name + ".in").c_str());
        system(("./" + name).c_str());
        assert(system(("diff -Z " + name + ".out " + name + to_string(i) + ".ans").c_str()) == 0);
    }
    cout << "AC!\n";

    return 0;
}