#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);
    ll tot=0,len=1,ans=1,cur=1;
    for(ll i=2;i<=n;i++)
    {
        tot+=len*(a[i]-a[i-1]);
        len++;
        while(cur<=n&&tot>m)
        {
            tot-=(a[i]-a[cur]);
            len--;
            cur++;
        }
        ans=max(ans,len);
        if(cur>n)   break;
    }
    cout<<ans;
    return 0;
}
