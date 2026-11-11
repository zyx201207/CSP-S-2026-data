#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int  n;
    cin>>n;
    string s[n+2];
    int a[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>s[i];
    }
    string m=s[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            m+=s[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<m;
    }
    return 0;
}
