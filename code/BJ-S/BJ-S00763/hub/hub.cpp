#include<bits/stdc++.h>
#define pow power
#define ll long long
#define ull unsigned long long
using namespace std;
template<typename T>void read(T &x)
{
    x=0;int f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=f;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writeln(T x){write(x);putchar('\n');}
template<typename T>void writesp(T x){write(x);putchar(' ');}
const int N=1e6+5;
struct node
{
    int v,nxt;
} edge[N<<1];
int head[N],cnt;
void add(int x,int y)
{
    edge[++cnt]={y,head[x]};
    head[x]=cnt;
}
int eu[N],ev[N];
int col[N];
int n,k;
int dep[N];
vector<int> vec;
vector<int> vecu,vecv;
void color(int x,int fa,int val)
{
    col[x]=val;vec.push_back(x);
    for(int i=head[x];i!=-1;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(v==fa) continue;
        dep[v]=dep[x]+1;
        color(v,x,val);
    }
}
int fa[N];
int mxdep[N];
void dfs(int x)
{
    mxdep[x]=dep[x];
    for(int i=head[x];i!=-1;i=edge[i].nxt)
    {
        int v=edge[i].v;
        if(col[x]!=col[v]||v==fa[x]) continue;
        dep[v]=dep[x]+1;
        fa[v]=x;
        dfs(v);
        mxdep[x]=max(mxdep[x],mxdep[v]);
    }
}
int buck[N];
int solve(int u,int v)
{
    vec.clear();
    dep[u]=0;
    color(u,v,1);
    vecu=vec;
    vec.clear();
    dep[v]=0;
    color(v,u,2);
    vecv=vec;
    int rtu=u,rtv=v;
    for(int x:vecu) if(dep[x]>dep[rtu]) rtu=x;
    for(int x:vecv) if(dep[x]>dep[rtv]) rtv=x;
    dep[rtu]=0;fa[rtu]=-1;
    dfs(rtu);
    dep[rtv]=0;fa[rtv]=-1;
    dfs(rtv);
    int c;
    for(int x:vecu) if(dep[x]>dep[rtu]) rtu=x;c=dep[rtu]/2;while(c--) rtu=fa[rtu];
    for(int x:vecv) if(dep[x]>dep[rtv]) rtv=x;c=dep[rtv]/2;while(c--) rtv=fa[rtv];
    dep[rtu]=0;fa[rtu]=-1;
    dfs(rtu);
    dep[rtv]=0;fa[rtv]=-1;
    dfs(rtv);
    for(int x=0;x<=n;x++) buck[x]=0;
    for(int x=0;x<=n;x++)
        if(x!=rtu&&x!=rtv)
            buck[mxdep[x]-dep[x]]++;
    for(int i=n-1;i>=0;i--)
        buck[i]+=buck[i+1];
    int res=n;
    for(int i=1;i<=n;i++)
        if(buck[i]<=k-2)
            res=min(res,i);
    return res;
}
vector<int> vecr;
void solve()
{
    for(int i=1;i<=n;i++) head[i]=-1,col[i]=0;cnt=0;
    read(n);read(k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        read(u);read(v);
        eu[i]=u,ev[i]=v;
        add(u,v);
        add(v,u);
    }
    int rt=1;
    dep[rt]=0;fa[rt]=-1;
    dfs(rt);
    for(int x=1;x<=n;x++) if(dep[x]>dep[rt]) rt=x;
    dep[rt]=0;fa[rt]=-1;
    dfs(rt);
    for(int x=1;x<=n;x++) if(dep[x]>dep[rt]) rt=x;
    int tmp=rt,tmpc=dep[rt];
    vecr.clear();
    while(tmpc--){vecr.push_back(tmp);tmp=fa[tmp];}vecr.push_back(tmp);
    int ans=n;
    // for(int i=1;i<vecr.size();i++) cout<<solve(vecr[i-1],vecr[i])<<" ";cout<<endl;
    int mid=vecr.size()/2;
    for(int i=max(1,mid);i<=min((int)vecr.size()-1,mid+1);i++) ans=min(ans,solve(vecr[i-1],vecr[i]));


    if(n<=4000) for(int i=1;i<n;i++) ans=min(ans,solve(eu[i],ev[i]));
    writeln(ans);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    memset(head,-1,sizeof(head));
    int cid,T;
    read(cid);read(T);
    while(T--) solve();
    return 0;
}
//g++ tmp.cpp -o tmp -std=c++14 -O2 -Wall -Wextra -static