#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=2e5+10,M=2e5+10;
mt19937 rnd(random_device{}());
int tc,T;
namespace Anaxa{
    int n,K,u[N],v[N];
    vector<int>e[N];
    int LIM;
    int vis[N];
    int res[N];
    void dfs(int x,int fa)
    {
        res[x]=-LIM;
        for ( auto v:e[x] )
        {
            if(v==fa||vis[v])continue;
            dfs(v,x);
            if(res[v]>0)res[x]=0;
            else res[x]=max(res[x],res[v]+1);
        }
        if(res[x]>=0)
        {
            res[x]=1;
            for ( auto v:e[x] )
                if(v!=fa&&!vis[v]&&res[v]>0)res[x]+=res[v];
        }
    }
    void dfs2(int x,int fa,int nowans,int &ans)//nowans<=0 则为外面到 x 时至少还有多少步才能产生贡献，否则为外面已经标记了几个点
    {
        // cerr << "dfs2 " << x << " " <<fa << " " << nowans << " " << max(0ll,nowans)+(res[x]<0?1ll:res[x]) << endl;
        ans=min(ans,max(0ll,nowans)+(res[x]<0?1ll:res[x]));
        int sum=0,mx1=-inf,mx2=-inf;
        for ( auto v:e[x] )
        {
            if(vis[v]||v==fa)continue;
            if(res[v]>mx1)
            {
                mx2=mx1;
                mx1=res[v];
            }else if(res[v]>mx2)mx2=res[v];
            if(res[v]>0)sum+=res[v];
        }
        for ( auto v:e[x] )
        {
            if(vis[v]||v==fa)continue;
            if(nowans>0)dfs2(v,x,nowans+sum-(res[v]>0?res[v]:0ll)+1,ans);
            else{
                if(res[v]==mx1&&mx2<0)
                {
                    int nv=max({nowans+1,-LIM+1,mx2+2});
                    dfs2(v,x,nv,ans);
                }else if(res[v]>0&&sum!=res[v])
                {
                    dfs2(v,x,sum-res[v]+1,ans);//res[v]>0,mx2>0
                }else{
                    assert(res[v]<=0);
                    if(sum>0)dfs2(v,x,sum+1,ans);
                    else if(res[v]==mx1)dfs2(v,x,max({nowans+1,-LIM+1,mx2+2}),ans);
                    else dfs2(v,x,max({nowans+1,-LIM+1,mx1+2}),ans);
                    // dfs2(v,x,max({nowans+1}))
                }
            }
        }
    }
    int slv(int x)
    {
        // cerr << "slv(" << x << ")\n";
        dfs(x,0);
        // for ( int i = 1 ; i <= n ; i++ )cerr << res[i] << " ";cerr << endl;
        int ans=res[x];
        if(ans<0)return 1;
        dfs2(x,0,-inf,ans);
        return (ans<0?1:ans);
    }
    int check()
    {
        // cerr << "LIM=" <<LIM << endl;
        int res=inf;
        for ( int i = 1 ; i < n ; i++ )
        {
            vis[u[i]]=1;
            int cnt=slv(v[i]);
            vis[u[i]]=0,vis[v[i]]=1;
            cnt+=slv(u[i]);
            vis[v[i]]=0;
            res=min(res,cnt);
            // cerr << u[i] << " " << v[i] << " " << cnt << endl;
        }
        int v=slv(1);
        // cerr << "x " << v << endl;
        return min(res,v)<=K;
    }
    void solve()
    {
        cin >> n >> K;
        for ( int i = 1 ; i <= n ; i++ )e[i].clear();
        for ( int i = 1 ; i < n ; i++ )
        {
            cin >> u[i] >> v[i];
            e[u[i]].push_back(v[i]);
            e[v[i]].push_back(u[i]);
        }
        if(K==n)return cout << "0\n",void();
        // LIM=1;vis[7]=1;
        // cerr << slv(1) << endl;
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;LIM=mid;
            if(check())r=mid;
            else l=mid+1;
        }
        cout << l << endl;
    }
	void main()
	{
		cin >> tc >> T;
        while(T--)solve();
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	Anaxa::main();
	return 0;
}
/*
先二分答案，然后可以试图将树划分为两个部分，每个部分都求一个最小答案
具体的每个部分我们都试图求出这个树里面如果最小通勤时间是 L 那么我们至少需要多少个点。
我们先考虑这个问题能不能做到一个比较人类的复杂度。
一个十分简单的做法是直接枚举一个根，然后每个点往上跳 L 步并标记这里到根的所有点。最后标记的点的个数就是这个根的答案。
于是我们得到了一棵树一个 L $O(n^2)$ 的做法。直接写可以获得 30pts（总复杂度 $O(n^3\log n)$）
这个过程显然是十分浪费的。我们每次换根的时候完全没有必要重新标记。
具体的，如果某个子树的高度达到了 L+1 那么这个子树的根就要被标记，否则不需要（根除外）。
那我们实际上可以计算每个点在根从各个方向来的时候他是否要被标记。当然事实上更好维护的是当根没有从某个方向来的时候的在这个方向上高度是多少
我们换根的时候完全可以维护这个过程。写得好看可能有 50
先这样吧，再回去看一下 T3
也许我们要换根套换根？切割的时候是一个换根，然后动态维护答案?
额我们先给原树钦定一个根，就是 1 吧。然后求出每个子树里的答案。如果这个子树不需要被标记那么就记录还需要多少高度才会标记点
哦时间有点来不及了，先写暴力。
6:26 踩着点写完暴力了，怎么时间这么不够用
50pts

有点完蛋了，我不会是唯一一个没上 300 的吧
298 烂完了。
而且一个都没拍/xk
*/
/*
g++ hub.cpp -O2 -std=c++14 -static
./a.out < hub1.in > hub.out
diff hub.out hub1.ans -Z -B
./a.out < hub2.in > hub.out
diff hub.out hub2.ans -Z -B
./a.out < hub3.in > hub.out
diff hub.out hub3.ans -Z -B
*/
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/