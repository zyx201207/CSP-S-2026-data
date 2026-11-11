#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n, m, a[N], sum[N], ans;
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    ll l=1;
    for(ll r=1;r<=n;r++)
    {
        while(l+1<=r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m) l++;
        if(a[r]*(r-l+1)-(sum[r]-sum[l-1])<=m)
        {
            ans=max(ans, r-l+1);
        }
    }
    cout<<ans;
    return 0;
}
