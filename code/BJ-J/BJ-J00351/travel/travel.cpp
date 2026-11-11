#include <bits/stdc++.h>
using namespace std;
string s1,t1,s2,t2;
int flag=1;
int isleft(char ch)
{
    if ('A'<=ch && ch<='C') return 1;
    else return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> s1 >> t1 >> s2 >> t2;
    if (s1!=s2) flag=0;
    cout << flag;
    if (t1.substr(0,2)!=t2.substr(0,2)) flag=0;
    cout << flag;
    if (isleft(t1[2])!=isleft(t2[2])) flag=0;
    cout << flag;
    if (t1[2]!=t2[2]+1 && t1[2]+1!=t2[2]) flag=0;
    cout << flag;
    return 0;
}