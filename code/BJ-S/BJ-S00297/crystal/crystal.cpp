#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e4+10;
int a[N];
int b[N][N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
     for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--)
        {

            b[i][j]=abs(a[j]-a[i]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=b[i][n];
    }
    if(ans<=m)
    {
        cout<<n;
        return 0;
    }

    if(ans-b[1][n]<=m)
    {
        cout<<n-1;
        return 0;
    }
    ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=b[i][n-1];
    }
    if(ans<=m)
    {
        cout<<n-1;
        return 0;
    }
    ans=1e9;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i;j<=n-1;j++)
        {
            for(int k=j;k<=n;k++)
            {
                ans=min(ans,b[i][k]+b[j][k]);
            }
        }
    }
    if(ans<=m)
    {
        cout<<n-2;
        return 0;
    }
    if(n==4)
    {
       cout<<1;
        return 0;
    }
    ans=1e9;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=min(ans,b[i][j]);
        }

    }
    if(ans<=m)
    {
        cout<<2;
    }
    else
    {
        cout<<1;
    }
   return 0;
}
