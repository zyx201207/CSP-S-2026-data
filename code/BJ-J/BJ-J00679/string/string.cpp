#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin; fin.open("string.in");
    ofstream fout; fout.open("string.out");
    int n, len = 0;
    string s = "";
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        char c;
        fin >> x >> c;
        for (int j = 0; j < x; j++) s += c;
        len += x;
    }
    //debugger fout << len << '\n';
    int ans = 0;
    for (int i = 0; i < len / 2; i++) {
        //debugger fout << i << ' ' << s[i] << ' ' << s[len - i - 1] << " : ";
        if (s[i] != s[len - 1 - i]) ans++;
        //debugger fout << ans << '\n';
    }
    fout << ans;
    fin.close(); fout.close(); return 0;
}