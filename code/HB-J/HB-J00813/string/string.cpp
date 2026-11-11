#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a;
char c;
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            s+=c;
        }
    }
    int ls=s.length(),ans=0;
    for(int i=0,j=ls-1;i<ls;i++,j--)
    {
        if (s[i]!=s[j])
        {
            s[i]=s[j];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}