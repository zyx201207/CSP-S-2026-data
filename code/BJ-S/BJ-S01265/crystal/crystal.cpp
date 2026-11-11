#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m,ans;
int a[500005];

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        a[i]+=1e12;
    }
    int l=1,tot=0;
    for(int r=1;r<=n;r++)
    {
        tot+=a[r];
        while(l<r&&a[r]*(r-l+1)>tot+m)
        {
            tot-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);
}
