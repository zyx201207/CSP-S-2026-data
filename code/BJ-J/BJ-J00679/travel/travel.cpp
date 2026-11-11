#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin; fin.open("travel.in");
    ofstream fout; fout.open("travel.out");
    int c1, c2;
    string s1, s2;
    bool x[4] = {0,0,0,0};
    fin >> c1 >> s1 >> c2 >> s2;
    x[0] = (c1 == c2);
    x[1] = x[0] && s1[0] == s2[0] && s1[1] == s2[1];
    if (s1[2] == 'D' || s1[2] == 'F') x[2] = s2[2] == 'D' || x[2] == 'F';
    else x[2] = s2[2] != 'D' && s2[2] != 'F';
    x[2] = x[2] && x[1];
    x[3] = x[2] && (s1[2] != 'A' && s1[2] != 'C' || s2[2] != 'A' && s2[2] != 'C');
    fout << x[0] << x[1] << x[2] << x[3];
    fin.close(); fout.close(); return 0;
}