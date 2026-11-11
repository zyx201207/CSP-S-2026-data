#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],l,r,ans,p[500005];
bool check(int x){
    for (int i=n;i-x+1>=1;i--)
    {
        ll num,l=i-x+1;
        ll d=a[i]-a[l];
        num=p[i]-p[l]-(l-1)*d;
        if (num<=m)
        {
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    r=n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
    {
        ll d=a[i]-a[i-1];
        p[i]=p[i-1]+d*(i-1);
    }
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if (check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
