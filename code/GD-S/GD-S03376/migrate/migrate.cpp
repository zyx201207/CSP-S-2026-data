#include<stdio.h>
using ll=long long;
const int N=2000005;
int idd,t,n;ll dis,s[N],ans;
int fir[N],num,in[N],inn[N];
ll f[N],mn[N];int que[N],l,r;
struct ss{int ed,nxt;}bia[N];
int erfen(int wh)
{
    int l=wh+1,r=n,rt=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(s[mid]-s[wh]<=dis)
        rt=mid,l=mid+1;else r=mid-1;
    }return rt;
}
void clear()
{
    for(int i=1;i<=n;i++) fir[i]=f[i]=0,mn[i]=1e18;
    for(int i=1;i<=num;i++) bia[i]=(ss){0,0};
    num=ans=0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%d%d",&idd,&t);while(t--)
    {
        scanf("%d%lld",&n,&dis);clear();
        for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
        if(idd==11||idd==12)
        {
            if((s[2]-s[1])*2>dis||s[n]-s[1]<=dis) printf("0\n");
            else printf("%lld\n",n-2*(dis/(s[2]-s[1]))+1);
            continue;
        }
        if(idd==13||idd==14)
        {
            for(int i=1;i<=n;i++)
            {
                int wh1=erfen(i);if(wh1==-1||wh1<=i) continue;
                int wh2=erfen(wh1-1);if(wh2==-1||wh2<=wh1) continue;
                if(wh1>1&&s[wh2]-s[wh1-2]<=dis) continue;ans++;
            }printf("%lld\n",ans);continue;
        }
        for(int i=1;i<n;i++)
        for(int j=i+1;j<=n&&s[j]-s[i]<=dis;j++)
        bia[++num].ed=j,bia[num].nxt=fir[i],
        fir[i]=num,inn[j]++;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) f[j]=0,in[j]=inn[j],mn[j]=1e18;
            l=0,que[r=1]=i,f[i]=1,mn[i]=0;while(l<r)
            {
                l++;for(int j=fir[que[l]];j;j=bia[j].nxt)
                {
                    if(mn[bia[j].ed]>mn[que[l]]+1)
                    f[bia[j].ed]=f[que[l]],mn[bia[j].ed]=mn[que[l]]+1;
                    else if(mn[bia[j].ed]==mn[que[l]]+1)
                    f[bia[j].ed]+=f[que[l]];
                    in[bia[j].ed]--;
                    if(!in[bia[j].ed]) que[++r]=bia[j].ed;
                }
            }for(int j=1;j<=n;j++) if(f[j]==2) ans++;
            for(int j=fir[i];j;j=bia[j].nxt) inn[bia[j].ed]--;
        }printf("%lld\n",ans);
    }
}
