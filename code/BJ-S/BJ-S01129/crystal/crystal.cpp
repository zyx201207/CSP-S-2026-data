#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
int s[500010],ans;
bool check(int l,int r)
{
    int len=r-l+1;
    int sum=s[r]-s[l-1];
    sum=len*a[r]-sum;
    return sum<=m;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,i))
                r=mid-1;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
