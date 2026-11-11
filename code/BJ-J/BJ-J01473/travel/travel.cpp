#include<bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;

int check(char ch) {
    if (ch == 'A' || ch == 'B' || ch == 'C') return 1;
    return 2;
}

bool check1(char ch1,char ch2) {
    if (ch1 == 'A' && ch2 == 'B') return true;
    if (ch1 == 'B' && ch2 == 'C') return true;
    if (ch1 == 'D' && ch2 == 'F') return true;
    if (ch2 == 'A' && ch1 == 'B') return true;
    if (ch2 == 'B' && ch1 == 'C') return true;
    if (ch2 == 'D' && ch1 == 'F') return true;
    return false;
}

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> c1 >> s2 >> c2;
    if (s1 == s2) cout << 1;
    else cout << 0;
    string tmp1 = c1.substr(0,2),tmp2 = c2.substr(0,2);
    if (s1 == s2 && tmp1 == tmp2) cout << 1;
    else cout << 0;
    if (s1 == s2 && tmp1 == tmp2 && check(c1[2]) == check(c2[2])) cout << 1;
    else cout << 0;
    if (s1 == s2 && tmp1 == tmp2 && check1(c1[2],c2[2])) cout << 1;
    else cout << 0;
    return 0;
}
