#include<iostream>
using namespace std;
int c,t,n;
long long k;
long long x[2000001],sum[2000001],f[2000001],cnt[2000001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=0;i<n;i++)scanf("%lld",&x[i]);
        if(c==11||c==12)
        {
            int d=min(k/(x[1]-x[0]),n-1ll);
            printf("%lld\n",(d>1&&2*d<=n)?n-2*d+1:0);
        }
        else if(c==13||c==14)
        {
            int pl=-1,pr=-1;
            for(int i=0;i<n;i++)
                if(x[i]-x[0]<=k&&x[n-1]-x[i]<=k)
                {
                    if(pl<0)pl=i;
                    pr=i;
                }
            if(pl==pr)
            {
                int cnt=0;
                for(int i=pr+1;i<n;i++)cnt+=(x[i]-x[pl-2]>k&&x[i]-x[pl-1]<=k);
                printf("%lld\n",(pl-1ll)*cnt);
            }
            else if(pr-pl==1)
            {
                int ed=pr+1;
                for(;ed<n&&x[ed]-x[pl-1]<=k;ed++);
                printf("%lld\n",1ll*pl*(n-ed));
            }
            else printf("0\n");
        }
        else
        {
            int ans=0;
            for(int st=0;st<n;st++)
            {
                sum[st]=1;
                f[st]=0;
                for(int i=st+1,j=st,p=st;i<n;i++)
                {
                    if(x[i]-x[i-1]>k)break;
                    while(j<i&&x[i]-x[j]>k)j++;
                    p=max(p,j);
                    while(p<i-1&&f[p+1]==f[j])p++;
                    f[i]=f[j]+1;
                    cnt[i]=sum[p]-(j>st?sum[j-1]:0);
                    sum[i]=sum[i-1]+cnt[i];
                    if(cnt[i]==2)ans++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
