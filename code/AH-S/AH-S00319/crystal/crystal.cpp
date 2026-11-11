#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],f[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    ll m;
    cin>>n>>m;
    f[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    f[1]=a[1];
    for(int i=2;i<=n;i++)
        f[i]+=f[i-1]+a[i];
    ll s=1,t,b;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            ll l=i-j;
          //  cout<<i<<" "<<j<<" "<<a[i]*l-f[i-1]+f[j-1]<<'\n';
             if(m>=abs(a[i]*l-f[i-1]+f[j-1] )) s=max(s,l+1);
        }
    }
    cout<<s;//<<" "<<abs( (b-t)*a[b]-sum )<<" "<<sum<<" "<<t<<" "<<b<<' '<<b-t+1<<" "<<f[n];
   // cout<<'\n'<<abs(a[3845]*3844-f[3844]);
    return 0;
}
