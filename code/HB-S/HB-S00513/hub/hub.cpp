#include <bits/stdc++.h>
using namespace std;
struct edge
{
    long long v,nxt;
}e[2000001];
long long c,t,n,k,u,v,h[1000001],dis[1000001],dd[1000001],del[1000001],col[1000001],bl[1000001],fr[1000001],cnt=0;
void add_edge(long long u,long long v)
{
    e[++cnt].nxt=h[u];
    e[cnt].v=v;
    h[u]=cnt;
}

void getdis(long long x,long long pr,long long c)
{
    fr[x]=pr,dis[x]=dis[pr]+1,col[x]=c;
    for(int i=h[x];i;i=e[i].nxt)
        if(e[i].v!=pr&&!del[e[i].v])getdis(e[i].v,x,c);
}

void cover(long long x,long long c)
{
    col[x]=c;
    for(int i=h[x];i;i=e[i].nxt)
        if(bl[e[i].v]&&!col[e[i].v])cover(e[i].v,c);
}

void bf()
{
    long long ans=1e18;
    for(int s=0;s<(1<<n);s++)
        {
        long long cc=0,cb=0,now=-1e18;
        for(int i=1;i<=n;i++)dd[i]=1e18;
        for(int i=1;i<=n;i++)
            if(s&(1<<(i-1)))bl[i]=1,cb++;
            else bl[i]=0;
        if(cb!=k)continue;
        for(int i=1;i<=n;i++)col[i]=0;
        for(int i=1;i<=n;i++)
            if(bl[i]&&!col[i])cc++,cover(i,cc);
        if(cc>2)continue;
        for(int i=1;i<=n;i++)
            if(bl[i])
               {
               dis[i]=0,getdis(i,0,0);
               for(int j=1;j<=n;j++)dd[j]=min(dd[j],dis[j]);
               }
        for(int i=1;i<=n;i++)now=max(now,dd[i]);
        ans=min(ans,now);
        }
    printf("%lld\n",ans-1);
}

pair<long long,long long>getmiddle(long long rt)
{
    dis[rt]=0,getdis(rt,0,0);
    long long mx=-1e18,p=0;
    pair<long long,long long>res(0,0);
    for(int i=1;i<=n;i++)
        if(dis[i]>mx)mx=dis[i],p=i;
    dis[p]=0,getdis(p,0,0);
    mx=-1e18,p=0;
    for(int i=1;i<=n;i++)
        if(dis[i]>mx)mx=dis[i],p=i;
    res.first=mx-1;
    mx=(mx-1)/2;
    while(mx)p=fr[p],mx--;
    res.second=p;
    return res;
}

void subk2()
{
    pair<long long,long long>mx(-1e18,-1e18);
    long long p=getmiddle(1).second,len=getmiddle(1).first,q=0,ans=-1e18;
    del[p]=1;
    for(int i=h[p];i;i=e[i].nxt)mx=max(mx,getmiddle(e[i].v));
    q=mx.second;
    del[p]=0;
    for(int i=1;i<=n;i++)dd[i]=1e18;
    dis[p]=0,getdis(p,0,0);
    for(int j=1;j<=n;j++)dd[j]=min(dd[j],dis[j]);
    if(q>0)
       {
       dis[q]=0,getdis(q,0,0);
       for(int j=1;j<=n;j++)dd[j]=min(dd[j],dis[j]);
       }
    for(int i=1;i<=n;i++)ans=max(ans,dd[i]);
    printf("%lld\n",min(ans-1,(len+1)/3));
}

int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
       {
       scanf("%lld%lld",&n,&k);
       for(int i=1;i<=n;i++)h[i]=del[i]=col[i]=cnt=0;
       for(int i=1;i<=n-1;i++)scanf("%lld%lld",&u,&v),add_edge(u,v),add_edge(v,u);
       if(n<=10)bf();
       else subk2();
       }
    return 0;
}
