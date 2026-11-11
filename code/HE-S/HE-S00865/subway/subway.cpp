#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5+10,Q=1e5+10;
long long ans[Q],w[N],floyd[510][510];
vector<pair<int,long long> > g[N];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    memset(ans,0x3f,sizeof ans);
    memset(floyd,0x3f,sizeof floyd);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        floyd[i][i]=0;
        for(long long j=1,v,w;j<=k;j++)
        {
            cin>>v>>w;
            g[v].push_back({m+i,w});
            g[m+i].push_back({v,w});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto j:g[i])
        {
            for(auto k:g[i])
            {
                floyd[j.first-m][k.first-m]=min(floyd[j.first-m][k.first-m],j.second+k.second);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        long long ans=0x3f3f3f3f3f3f3f3f;
        for(auto j:g[u])
        {
        	for(auto k:g[v])
        	{
        		ans=min(ans,j.second+k.second+floyd[j.first-m][k.first-m]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
    }
    
}
/*
太难读题了这也。
盲猜根号题。
诶好像不用根号，nmlog是不是太悬了
图是好建的。那么总共有 n+m 个顶点， \sum k_i 条边。

那么我们思考此时这个 d 还没有用。
也就是说，边数是 min(dm,\sum k_i) 的。

我们肯定是枚举对于每个线路，u到它+v到它的距离之和。
考虑对于每个地铁站求最短路的时间复杂度。

性质B可以01bfs

空间大可以离线一下。

我们猜测这个 d 是让你证明时间复杂度的。我们直接大胆写！

时间复杂度是错的。

欸，我有一计。建立一个源点。

问题来了，如何预处理出这个每两个线路之间的最短路呢
欸，我有一计。直接暴力，对于每个车站连的线路，d^2枚举两两之间的边。是不是做完了！
*/
