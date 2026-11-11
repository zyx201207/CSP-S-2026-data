#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string slice(string s, unsigned int start, unsigned int end) {
    if (end > s.size()) {
        throw "Input out of range!";
    }
    if (start > end) {
        throw "Invalid input!";
    }
    if (start == end) {
        return "";
    }
    string res = "";
    res[0] = s[start];
    for (unsigned int i = start + 1; i < end; i++) {
        res += s[i];
    }
    return res;
}

bool compare(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) {
        return false;
    }
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

bool same_side(char a, char b) {
    if (a <= 'C' && b <= 'C') {
        return true;
    }
    if (a >= 'D' && b >= 'D') {
        return true;
    }
    return false;
}

bool near(char a, char b) {
    if (a == b) {
        throw "Invalid input!";
    }
    if (a > b) {
        return near(b, a);
    }
    if ((a == 'A' && b == 'B') ||
        (a == 'B' && b == 'C') ||
        (a == 'D' && b == 'F')
    ) {
        return true;
    }
    return false;
}

int main() {
    freopen("./travel.in", "r", stdin);
    freopen("./travel.out", "w", stdout);
    string c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    bool same_train = c1 == c3;
    bool same_line = (slice(c2, 0, 2) == slice(c4, 0, 2)) && same_train;
    bool at_same_side = same_side(c2[2], c4[2]) && same_line;
    bool near_by = near(c2[2], c4[2]) && at_same_side;
    // cout << same_train << same_line << at_same_side << near_by << endl;
    cout << same_train << same_line << at_same_side << near_by << endl;
    return 0;
}
