#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,s[500005],sum[500005];
inline bool check(int x,int i)
{
    int res=x*a[i];
    if(i-x<0) return 0;
    res-=s[i]-s[i-x];
    return res<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);    
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check(mid,i))
            {
                l=mid;
            }
            else r=mid-1;
        }
        ans=max(ans,l);
    }
    cout<<ans;


    return 0;
}