#include<bits/stdc++.h>
using namespace std;

/*
关注592080谢谢喵！

预计100+100+56+15=271pts

15:43 看题
15:45 最大最小？二分吗
15:46 有一个贪心思路，找到“一层”点，令0<=最远叶子的距离-到根的距离<=1，估计正解要换根，不会，写一下暴力准备跑路
15:48 吃士力架，零食-1，余1
15:50 显然不对，感觉不太会啊 goto->migrate
18:10 写暴力
18:25 写完了 
*/

int c;

void solve()
{
    int n,k;
    cin>>n>>k;

    vector<vector<int>> edge(n+1);
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        edge[u].emplace_back(v);
        edge[v].emplace_back(u);
    }

    vector<vector<int>> dis(n+1,vector<int>(n+1,0));
    auto dfs=[&](auto &&self,int u,int p,int rt)->void
    {
        dis[rt][u]=dis[rt][p]+1;
        for (auto v:edge[u])
            if (v!=p)
                self(self,v,u,rt);
    };
    for (int i=1;i<=n;i++)
        dfs(dfs,i,0,i);

    vector<int> vx(n+1),vis(n+1);
    auto check=[&](auto &&self,int u,int p)->void
    {
        vx[u]=1;
        for (auto v:edge[u])
            if (v!=p&&vis[v])
                self(self,v,u);
    };

    int ans=0x3f3f3f3f;
    auto calc=[&](auto &&self,int x,int cnt)->void
    {
        if (cnt==k)
        {
            int cnt=0;
            fill(vx.begin(),vx.end(),0);
            for (int i=1;i<=n;i++)
                if (vis[i]&&!vx[i])
                {
                    cnt++;
                    check(check,i,0);
                }
            if (cnt>2)
                return ;
            int res=0;
            for (int i=1;i<=n;i++)
                if (!vis[i])
                {
                    int tmp=0x3f3f3f3f;
                    for (int j=1;j<=n;j++)
                        if (vis[j])
                            tmp=min(tmp,dis[i][j]);
                    res=max(res,tmp-1);
                }
            ans=min(ans,res);
            return ;
        }
        if (x==n+1)
            return ;
        self(self,x+1,cnt);
        vis[x]=1;
        self(self,x+1,cnt+1);
        vis[x]=0;
    };
    calc(calc,1,0);
    cout<<ans;
}

signed main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    #ifndef LOCAL
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
    #endif

    int T=1;
    cin>>c>>T;

    while (T--)
    {
        solve();
        if (T)
            cout<<'\n';
    }
    return 0;
}