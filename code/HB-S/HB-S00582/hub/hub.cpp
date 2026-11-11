#include <iostream>
using namespace std;
const int N=1e6+5,MX=1e8;
int nxt[N],nt[N],h[N],top;
void add(int u,int v)
{
    top++;
    nxt[top]=v;
    nt[top]=h[u];
    h[u]=top;
}
int n,m,T,op,V[N],dep[N];
int v=0,CNT=0;
void dfs(int x,int pre)
{
    dep[x]=1;
    V[x]=0;
    for(int i=h[x];i;i=nt[i])
    {
        if(nxt[i]==pre)continue;
        dfs(nxt[i],x);
        V[x]+=V[nxt[i]];
        dep[x]=max(dep[x],dep[nxt[i]]+1);
    }
    if(dep[x]>op)
    {
        V[x]+=1;
    }
    return ;
}
void solve(int x,int pre,int mx,int len)
{
    if(mx+len>op||len>op)return ;//CNT+CNT
    int xm=0,es=0,p1=0,cnt=0;
    for(int i=h[x];i;i=nt[i])
    {
        if(nxt[i]==pre)continue;
        if(dep[nxt[i]]>=xm)
        {
            es=xm;
            xm=dep[nxt[i]];
            p1=nxt[i];
        }
        else
        {
            es=max(es,dep[nxt[i]]);
        }
        cnt+=V[nxt[i]];
    }
    if(xm+len<=op)
    {
        xm=-MX;
        es=-MX;
        p1=0;
    }
    if(es+len<=op)
    {
        es=-MX;
    }
    if(p1)
    {
        solve(p1,x,max(mx,es-len),len+1);
    }
    for(int i=h[x];i&&v==0;i=nt[i])
    {
        if(nxt[i]==pre||nxt[i]==p1)continue;
        solve(nxt[i],x,max(mx,xm-len),len+1);
        
    }
    if(cnt+CNT+1<=m)v=1;
    return ;
}
bool ck(int x)
{
    op=x;
    v=0;
    for(int i=1;i<=n&&v==0;i++)
    {
        dfs(i,i);
        CNT=0;
        for(int j=h[i];j;j=nt[j])
        {
            CNT+=V[nxt[j]];
        }
        for(int j=h[i];j;j=nt[j])
        {
            CNT-=V[nxt[j]];
            solve(nxt[j],i,-MX,1);
            /*if(v)
            {
                printf("AAA%d %d\n",i,nxt[j]);
            }*/
            CNT+=V[nxt[j]];
        }
    }
    return v;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&T,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
        {
            int _u,_v;
            scanf("%d%d",&_u,&_v);
            add(_u,_v);
            add(_v,_u);
        }
        int L=0,R=n;
        //cout<<ck(6)<<endl;
        //return 0;
        while(L!=R)
        {
            int mid=(L+R)/2;
            if(ck(mid))R=mid;
            else L=mid+1;
        }
        printf("%d\n",L);
        //cout<<ck(L)<<endl;
        for(int i=1;i<=n;i++)h[i]=0;
        top=0;
    }
    return 0;
}
/*
g++ hub.cpp -O0 -g -o  hub -std=c++14
gdb -q -tui ./hub
b 90
r

5 2
1 2


2 3
3 4
4 5
*/