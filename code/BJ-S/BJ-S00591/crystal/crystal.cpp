#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10;
int n,m,a[N];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int l=1,sum=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=(i-l)*(a[i]-a[i-1]);
        while(sum>m)
        {
            l++;
            sum-=a[i]-a[l-1];
        }
        ans=max(ans,i-l+1);
    }
    printf("%lld",ans);
    return 0;
}
