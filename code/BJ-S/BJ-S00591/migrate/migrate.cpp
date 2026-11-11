#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;
int c,t,n,d;
int x[N];
int rr[N],ll[N];
int rm[N],lm[N];

void solve()
{
    int ans=0;
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)
        rr[i]=ll[i]=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int i=n,j=n;i>=1;i--)
    {
        int w=x[i]-d;
        while(j>1 && x[j-1]>=w)
            j--;
        lm[i]=j;
        if(j!=i)
            rr[j]+=rr[i]+1;
    }
    for(int i=1,j=1;i<=n;i++)
    {
        int w=x[i]+d;
        while(j<n && x[j+1]<=w)
            j++;
        rm[i]=j;
        if(j!=i)
            ll[j]+=ll[i]+1;
    }
    for(int i=2;i<(n-1);i++)
    {
        int j=i+1;
        int a1,a2,b1,b2;
        a1=lm[j];
        a2=lm[j+1]-1;
        a2=min(a2,i-1);
        b1=rm[i-1]+1;
        b1=max(b1,j+1);
        b2=rm[i];
        if(a1<=a2 && b1<=b2)
        {
            ans+=(a2-a1+1+ll[a1])*(b2-b1+1+rr[b2]);
        }
    }
    printf("%lld\n",ans);
    return ;
}

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        solve();
    }
    return 0;
}
