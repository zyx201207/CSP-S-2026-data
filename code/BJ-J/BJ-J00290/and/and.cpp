#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],dp[200005],maxn;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    if(m==n)
    {
        for(int i=2;i<=n;i++) a[i]&=a[i-1];
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    for(int i=1;i<=m;i++) dp[i]=-1e9;
    dp[1]=maxn;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=2;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    cout<<dp[m];
}
