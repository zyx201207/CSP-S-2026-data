#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<ll> pre(n+1,0);
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];
    int l=0;
    int ans=0;
    for(int r=0;r<n;r++)
    {
        while(true)
        {
            int mid=(l+r)/2;
            ll left=mid-l;
            ll right=r-mid;
            ll cost=a[mid]*left-(pre[mid]-pre[l]);
            cost+=(pre[r+1]-pre[mid+1])-a[mid]*right;
            if(cost<=m) break;
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}