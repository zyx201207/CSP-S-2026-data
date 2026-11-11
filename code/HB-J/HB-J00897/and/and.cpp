#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[200005][200005];
string ejz(int t)
{
    string s="";
    string ss="";
    while(t!=0)
    {
        ss='0'+t%2;
        ss+=s;
        s=ss;
        t=t/2;
    }
    return s;
}
int q(int w)
{
    int e=1;
    for(int i=1;i<=w;i++)
        e=e*2;
    return e;
}
long long h(long long x,long long y)
{
    string s=ejz(x);
    string ss=ejz(y);
    long long g=0;
    for(int i=0;i<=min(s.size(),ss.size())-1;i++)
    {
        if(s[i]==ss[i])
        {
            g+=q(i);
        }
    }
    return g;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=max(dp[i-1][j],h(dp[i-1][j],a[i]));
    cout<<dp[n][m];
    return 0;
}
