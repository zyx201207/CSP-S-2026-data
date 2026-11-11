#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[500005],pr[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    sort(p+1,p+n+1);
    for(int i=n;i>=1;i--)
    {
        pr[i]=pr[i+1]+p[i];
    }
    for(int i=n;i>=1;i--)
    {
        int l=1,r=i,mid;
        while(l<=r)
        {
            mid=((l+r)>>1);
            if(pr[mid]-pr[i+1]+m>=p[i]*(i-mid+1))
                r=mid-1;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
        // cout<<i<<" "<<l<<" "<<r<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}