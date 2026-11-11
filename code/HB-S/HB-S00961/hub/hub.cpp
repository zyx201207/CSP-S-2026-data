#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int inf=1e9;
int cid,tc,n,k,x,y,F[maxn],siz[maxn];
vector<int> v[maxn];
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
int d1[maxn],d2[maxn],lim,sa[maxn],sb[maxn],rt;
inline void dfs(int x,int fa)
{
    F[x]=fa;
    for(auto y:v[x])if(y!=fa)dfs(y,x);
}
inline void dfs1(int x,int fa)
{
    d1[x]=d2[x]=sa[x]=sb[x]=0;
    for(auto y:v[x])
    {
        if(y==fa)continue;
        dfs1(y,x);
        d1[x]=max(d1[x],d1[y]+1);sa[x]+=sa[y];
    }
    sa[x]+=(d1[x]>=lim);
}
int M,pmx[maxn],smx[maxn];
inline void dfs2(int x,int fa)
{
    vector<int> sons;for(auto y:v[x])if(y!=fa)sons.push_back(y);
    int sz=(int)sons.size();
    for(int i=0;i<sz;i++)pmx[i]=max(((i==0)?-inf:pmx[i-1]),d1[sons[i]]+2);
    for(int i=sz-1;i>=0;i--)smx[i]=max(((i==sz-1)?-inf:smx[i+1]),d1[sons[i]]+2);
    for(int i=0;i<sz;i++)
    {
        int y=sons[i];
        d2[y]=max({d2[x]+1,((i==0)?-inf:pmx[i-1]),((i==sz-1)?-inf:smx[i+1])});
    }
    for(auto y:sons)dfs2(y,x);
}
inline void dfs3(int x,int fa,int ss)
{
    //if(lim==2 && rt==5)printf("x %d,d2 %d\n",x,d2[x]);
    if(x!=rt)ss-=(d1[x]>=lim),ss+=(d2[x]-1>=lim);
    M=min(M,sa[rt]+ss+(d1[x]<lim));
    for(auto y:v[x])if(y!=fa)dfs3(y,x,ss);
}
inline int sol(int x,int fa)
{
    rt=x;dfs1(rt,fa);
    M=inf;dfs2(rt,fa);dfs3(rt,fa,0);
    //if(lim==2)printf("sol %d %d:%d\n",rt,fa,M);
    return M;
}
inline int chk(int mid)
{
    int ans=inf;lim=mid;
    ans=min(ans,sol(1,0));
    //if(mid==1)printf("pans %lld\n",ans);
    for(int i=2;i<=n;i++)
    {
        if(ans<=k)break;
        ans=min(ans,sol(i,F[i])+sol(F[i],i));
    }
    return ans;
}
/*
1 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cid=read();tc=read();
    while(tc--)
    {
        n=read();k=read();
        for(int i=1;i<=n;i++)v[i].clear(),F[i]=0;
        for(int i=1;i<n;i++)x=read(),y=read(),v[x].push_back(y),v[y].push_back(x);
        dfs(1,0);
        if(k==n){puts("0");continue;}
        int l=1,r=n,res=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(chk(mid)<=k)res=mid,r=mid-1;
            else l=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}
