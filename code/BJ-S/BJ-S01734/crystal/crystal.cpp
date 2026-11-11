#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn=5e5+5;

ll n,m,a[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);

    ll sum=0,l=1,cnt=0,ans=0;
    for(ll i=1;i<=n;i++)
    {
        sum+=a[i];
        cnt++;
        while((a[i]*cnt-sum)>m)
        {
            sum-=a[l];
            l++;
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<'\n';

    return 0;
}
