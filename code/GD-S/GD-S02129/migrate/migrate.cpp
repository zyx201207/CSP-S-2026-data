#include<cstdio>
#include<iostream>
#define N 2000005
#define int long long
using namespace std;
int c,t;
int n,d;
int at[N];
int fr[N];
int bk[N];
int sumf[N];
int sumb[N];
int ans;
void solve()
{
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%lld",at+i);
    sumf[n]=0;
    for(int i=n-1,j=n;i>=1;i--)
    {
        while(at[j]-at[i]>d)j--;
        fr[i]=j-i;
        sumf[i]=0;
        if(fr[i]==1||fr[i]==fr[i+1]+1)sumf[i]=sumf[i+fr[i]]+1;
        if(fr[i]-fr[i-1]>0)sumf[i]+=fr[i]-fr[i-1];
    }
    for(int i=2,j=1;i<=n;i++)
    {
        while(at[i]-at[j]>d)j++;
        bk[i]=i-j;
        sumb[i]=0;
        if(bk[i]==1||bk[i]==bk[i-1]+1)sumb[i]=sumb[i-bk[i]]+1;
        if(bk[i]-bk[i+1]>0)sumb[i]+=bk[i]-bk[i+1];
    }
    ans=0;
    for(int i=2,l,r;i<n-1;i++)
    {
        l=i+1-bk[i+1],r=i+fr[i];
        if(fr[i]>=2&&bk[i+1]>=2&&fr[l]==bk[i+1]&&bk[r]==fr[i])
            ans+=((bk[l+1]==1?sumb[l]:(bk[l]-bk[l+1]>0?bk[l]-bk[l+1]:0))+bk[i+1]-bk[i+2]+1)*((fr[r-1]==1?sumf[r]:(fr[i]-fr[i-1]>0?fr[i]-fr[i-1]:0))+fr[i]-fr[i-1]+1);
    }
    printf("%lld\n",ans);
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
        solve();
    return 0;
}