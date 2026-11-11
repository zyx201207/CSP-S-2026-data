#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],dp[N],k[N];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(m==n)
    {
        long long ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(n*m>=50000000)
    {
        if(m==n-1)
        {
            long long ans=a[1];
            for(int i=2;i<=n;i++) ans=ans&a[i];
            for(int i=1;i<=n;i++)
            {
                double p=log2(a[i]);
                int y=p;
                if(pow(2,y)!=a[i]) y++;
                k[i]=y;
            }
            long long mx=-1;
            for(int i=1;i<=n;i++) mx=max(mx,ans&(1ll*int(pow(2,k[i]))-1ll*a[i]-1ll));
            cout<<mx;
            return 0;
        }
        sort(a+1,a+n+1,greater<int>());
        long long ans1=a[1];
        for(int i=2;i<=m;i++) ans1=ans1&a[i];
        cout<<ans1;
        return 0;
    }
    for(int i=0;i<=m;i++) dp[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=min(i*1ll,m);j>=1;j--)
        {
            if(dp[j]==0) dp[j]=a[i];
            else dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    cout<<dp[m];
    return 0;
}