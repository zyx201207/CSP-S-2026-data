#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+10;
int cid,tc,n,d,a[maxn],nxt[maxn],id[maxn];
int tot,st[maxn],ed[maxn];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')f=-f;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int f[maxn],g[maxn],h[maxn];
//f:# of paths to i s.t all tight
//g:# of paths to i s.t. all tight,last -1 not good
//h:# of paths s.t. exact one is not tight
inline int chk(int x,int y,int z)
{
    if(nxt[y-1]<z)return 0;//tight
    else if(y==x+1 || nxt[y-2]<z)return 1;//1
    return 2;
}
/*
1 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cid=read();tc=read();
    while(tc--)
    {
        n=read();d=read();
        for(int i=1;i<=n;i++)a[i]=read();
        int ptr=0;tot=0;
        for(int i=1;i<=n;i++)
        {
            while(ptr<n && a[ptr+1]<=a[i]+d)ptr++;
            nxt[i]=((ptr<=i)?0:ptr);
            if(nxt[i])tot++,st[tot]=i,ed[tot]=nxt[i],id[i]=tot;
        }
        for(int i=1;i<=tot;i++)f[i]=g[i]=h[i]=0;
        int ans=0;
        //f
        for(int i=1;i<=tot;i++)
        {
            f[i]++;int x=ed[i];
            if(nxt[x] && chk(st[i],ed[i],ed[id[x]])==0)f[id[x]]+=f[i];
        }
        //g
        for(int i=1;i<=tot;i++)
        {
            g[i]++;int x=ed[i];
            if(nxt[x])
            {
                int j=id[x];
                //if(x==2)printf("nxt %lld,ed %lld\n",nxt[x-1],ed[j]-1);
                if(nxt[x-1]<ed[j]-1)g[j]+=f[i];
            }
        }
        //h
        for(int i=1;i<=tot;i++)
        {
            if(!g[i])continue;
            //printf("st %lld,ed %lld,g %lld\n",st[i],ed[i],g[i]);
            int x=ed[i],lft=((ed[i]!=st[i]+1)?(nxt[x-2]+1):x+1),rgt=nxt[x-1];
            if(lft<=rgt)ans+=(rgt-lft+1)*g[i];
            if(nxt[x])
            {
                int j=id[x];
                if(chk(st[i],ed[i],ed[j])==1)h[j]+=g[i];//not tight
            }
        }
        //trans h
        for(int i=1;i<=tot;i++)
        {
            if(!h[i])continue;
            //printf("h %lld:%lld\n",i,h[i]);
            int x=ed[i],lft=nxt[x-1]+1,rgt=nxt[x];//this edge should be tight
            if(lft<=rgt)ans+=(rgt-lft+1)*h[i];
            if(nxt[x])
            {
                int j=id[x];
                if(chk(st[i],ed[i],ed[j])==0)h[j]+=h[i];//not tight
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
