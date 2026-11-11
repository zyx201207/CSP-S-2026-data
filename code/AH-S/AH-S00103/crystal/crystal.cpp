#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans;
long long m;
long long a[500005],sum[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i;
        while(l<r)
        {
            int mid=l+r>>1;
            if(sum[i-1]-sum[mid-1]+m>=(i-mid)*a[i])
                r=mid;
            else
                l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}