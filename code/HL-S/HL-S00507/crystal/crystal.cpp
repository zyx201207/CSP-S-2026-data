#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6;
ll a[N];
ll d[N];
pair<ll,ll> p[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        d[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++)
    {
        ll len=p[i-1].first+1;
        ll sum=p[i-1].second+len*d[i];
        if(p[i-1].second+(p[i-1].first+1)*d[i]>m)
        {
            while(sum>m)
            {
                sum-=a[i]-a[i-len];
                len--;
            }
        }
        p[i].first=len,p[i].second=sum;
    }
    ll maxx=0;
    for(int i=1;i<=n;i++)
        maxx=max(maxx,p[i].first);
    cout<<maxx+1;
    return 0;
}
