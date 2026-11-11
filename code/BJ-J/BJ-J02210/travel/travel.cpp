#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string c1, s1, c2, s2;
bool is1, is2, is3, is4;

bool isl(string s) {
    string l = "ABC";
    return l.find(s[2]) != string::npos;
}

bool is99() {
    string s = "ABCDF";
    return abs(int(s.find(s1[2])) - int(s.find(s2[2]))) == 1;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    is1 = c1 == c2;
    if (is1) {
        is2 = s1[0] == s2[0] && s1[1] == s2[1];
        if (is2) {
            is3 = (isl(s1) == isl(s2));
            if (is3) {
                is4 = is99();
            }
        }
    }
    cout << is1 << is2 << is3 << is4;

    return 0;
}
