#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char s[200002];
    int a[200002];
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        cin>>s[i];
    }
    if(n == 1)
    {
        cout<<0;
        return 0;
    }
    if(n == 2&&(s[1] == s[2]))
    {
        cout<<0;
        return 0;
    }
    if(n==2&&(s[1]!=s[2]))
    {
           cout<<min(a[1],a[2]);
           return 0;
    }
    if(s[1]==s[2])
    {
           cout<<0;
           return 0;
    }
    if(n==2&&(a[1]==a[2]))
    {
           cout<<0;
           return 0;
    }









    return 0;
}
