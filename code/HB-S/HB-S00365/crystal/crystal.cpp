#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N];
ll check(ll x)
{
    ll cnt=0,val=0;
    priority_queue<ll> pq;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x) continue;
        if(val+(x-a[i])<=m)
        {
            val+=(x-a[i]);
            cnt++;
            pq.push(x-a[i]);
        }
        else if(!pq.empty()&&x-a[i]<pq.top())
        {
            val-=pq.top();
            val+=(x-a[i]);
            pq.pop();
            pq.push(x-a[i]);
        }
    }
    if(cnt==1) return -1;
    return cnt;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll l=1,r=n,ans=1;
    while(l<=r)
    {
       ll mid=(r-l)/2+l;
       if(check(a[mid])!=-1)
       {
           ans=max(ans,check(a[mid]));
           l=mid+1;
       }
       else r=mid-1;
       //cout<<mid<<endl;
    }
    cout<<ans;
    return 0;
}
