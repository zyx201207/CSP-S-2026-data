#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    static int sgn, res; sgn = 0, res = 0; static char ch = getchar();
    while(!isdigit(ch)) sgn ^= (ch == '-'), ch = getchar();
    while(isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
    return sgn ? -res : res;
}

int c1, c2, r1, r2;
string s1, s2, t1, t2;

signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> s2 >> t1 >> t2;
    c1 = (s2[0] - '0') * 10 + (s2[1] - '0');
    c2 = (t2[0] - '0') * 10 + (t2[1] - '0');
    r1 = s2[2] - 'A' + 1;
    r2 = t2[2] - 'A' + 1;
    if(s1 == t1) cout << 1;
    else cout << 0;
    if(s1 == t1 && c1 == c2) cout << 1;
    else cout << 0;
    if(s1 == t1 && c1 == c2 && r1 >= 1 && r1 <= 3 && r2 >= 1 && r2 <= 3 || r1 >= 4 && r1 <= 5 && r2 >= 4 && r2 <= 5)
        cout << 1;
    else
        cout << 0;
    if(s1 == t1 && c1 == c2 && r1 >= 1 && r1 <= 3 && r2 >= 1 && r2 <= 3 && abs(r1 - r2) == 1)
        cout << 1;
    else if(s1 == t1 && c1 == c2 && r1 >= 4 && r1 <= 5 && r2 >= 4 && r2 <= 5 && abs(r1 - r2) == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}