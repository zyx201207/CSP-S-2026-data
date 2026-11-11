#include<bits/stdc++.h>
using namespace std;
inline bool same_row(string s1, string s2)
{
    if(s1[0] == s2[0] && s1[1] == s2[1])return 1;
    else return 0;
}
inline int check(string s1, string s2)
{
    char x = s1[2];
    char y = s2[2];
    if(x == 'D' && y == 'F' || x == 'F' && y == 'D' || x == 'A' && y == 'B' || x == 'B' && y == 'A' || x == 'B' && y == 'C' || x == 'C' && y == 'B')
        return 3;
    else if(x == 'A' && y == 'C' || x == 'C' && y == 'A')
        return 2;
    else
        return 0;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)cout << "0000\n";
    else if(!same_row(s1, s2))cout << "1000\n";
    else
    {
        int x = check(s1, s2);
        cout << 1 << 1 << (x & 2) / 2 << (x & 1);
    }
}
