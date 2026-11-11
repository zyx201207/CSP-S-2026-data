#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int _,T;
int n,k;
vector <int> tr[N];
int vis[N],f[N],cnt;

int dfs(int x,int _fa)
{
    if (vis[x]) return 0;
    int _size=tr[x].size(),v,res=n;
    for (int i=0;i<_size;i++)
    {
        if ((v=tr[x][i])==_fa) continue;
        res=min(res,dfs(v,x));
    }
    return res+1;
}
void dfs2(int x,int _fa)
{
    if (!vis[x]) return ;
    f[x]=cnt;
    int _size=tr[x].size();
    for (int i=0;i<_size;i++) if (tr[x][i]!=_fa) dfs2(tr[x][i],x);
}
void solve()
{
    cin>>n>>k; int u,v,ans=n; 
    for (int i=1;i<n;i++)
    {
        cin>>u>>v; 
        tr[u].push_back(v);
        tr[v].push_back(u);
    }

    for (int i=0;i<(1<<n);i++)
    {
        if (__builtin_popcount(i)!=k) continue;
        int tmp=0;
        for (int j=1;j<=n;j++) vis[j]=((i>>(j-1))&1),f[j]=0;
        cnt=0;
        for (int j=1;j<=n;j++) if (vis[j]&&!f[j]) cnt++,dfs2(j,0);
        if (cnt>2) continue;
        for (int j=1;j<=n;j++) tmp=max(tmp,dfs(j,0));
        ans=min(ans,tmp);
    }

    cout<<ans<<"\n";
    for (int i=1;i<=n;i++) tr[i].clear();
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>_>>T; while (T--) solve(); return 0;
}
/*
现在是18：18 按理来说我应该坐在家里复习即将来临的期中考试，但我却被西西佛抓来打S组

我只是一个退役了一年的高二学生，即将走入 OI 的坟墓，我没有敏捷的思维也没有超人的直觉，我又能打成什么样的成绩呢？

——T1 简单题，理解题意后直接秒了

——T2 是模板题变形，略有些小巧思，将地铁站的多源最短路转换为地铁线的多源最短路就能做出来了

——T3 我原本以为有数据结构在其中，后来才发现贡献的计算过于依赖先前的值，无法做到O(N^2)以下只能换种思路，对某种神秘的单位进行技术。我大概有些想法，但我懒得继续往下想了，反正O(N^2)的40pts给的挺慷慨的

——T4 直接弃了。文化课选手没必要死磕 T4

现在是 18：25

去年的 CSP-S，我没有拿到理想的分数。那是我第一次直面理想与现实的差距。

我总是在想，OI究竟给我带来了什么？

唉

如果能重来，我不要再选择OI了
*/