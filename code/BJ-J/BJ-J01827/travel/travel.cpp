#include <bits/stdc++.h>
using namespace std;
bool check(string a, string b)
{
    return (a[2] <= 'C' && b[2] <= 'C' || a[2] >= 'D' && b[2] >= 'D');
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    bool flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    string s1, c1, s2, c2;
    cin>>s1>>c1>>s2>>c2;
    if(s1 == s2)flag1 = 1;
    if(flag1 && c1.substr(0, 2) == c2.substr(0, 2))flag2 = 1;
    if(flag2 && check(c1, c2))flag3 = 1;
    if(flag3 && abs(c1[2] - c2[2]) <= 1)flag4 = 1;
    cout<<flag1<<flag2<<flag3<<flag4;
    return 0;
}