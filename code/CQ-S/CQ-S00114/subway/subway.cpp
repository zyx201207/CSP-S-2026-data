#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10,M=2e5+10;
mt19937 rnd(random_device{}());
int tc;
namespace Anaxa{
    int n,m,d,q;
    vector<pair<int,int>>e[N];
    int dis[510][510],w[N];
	void main()
	{
		cin >> tc >> n >> m >> d >> q;
        for ( int i = 1 ; i <= m ; i++ )cin >> w[i];
        for ( int i = 1 ; i <= n ; i++ )
        {
            int k;cin >> k;
            while(k--)
            {
                int x,d;cin >> x >> d;
                e[x].push_back({i,d});
            }
        }
        for ( int i = 1 ; i <= m ; i++ )assert(e[i].size()<=d);
        memset(dis,0x3f,sizeof(dis));
        for ( int i = 1 ; i <= n ; i++ )dis[i][i]=0;
        for ( int i = 1 ; i <= m ; i++ )
            for ( auto [x1,d1]:e[i] )
                for ( auto [x2,d2]:e[i] )
                    dis[x1][x2]=min(dis[x1][x2],d1+d2);
        // cerr << "debug\n";
        for ( int k = 1 ; k <= n ; k++ )
            for ( int i = 1 ; i <= n ; i++ )
                for ( int j = 1 ; j <= n ; j++ )
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        // cerr << "debug\n";
        while(q--)
        {
            int u,v,ans=inf;cin >> u>> v;
            for ( auto [x1,d1]:e[u] )
                for ( auto [x2,d2]:e[v] )
                    ans=min(ans,d1+d2+dis[x1][x2]);
            cout << ans+w[u]+w[v] << endl;
        }
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Anaxa::main();
	return 0;
}
/*
我手上有一个猎奇的 $O(n^3+d\sum k+qd^2)$ 的做法。

首先问题可以建模成每个地铁口到站台连边，每个站台到线路连边。
现在我们直接看线路之间的关系。每个站台都不要了，我们直接在站台对应的线路之间两两连边。之后线路之间的代价就可以 floyd 计算
然后考虑询问。询问首先地铁口到站台的代价是固定的 w_u+w_v。然后枚举 u 进了哪条线，v 进了哪条线。就是这个复杂度了
额最大的 floyd 部分是一个极小常数的东西，应该没问题。
*/
/*
g++ subway.cpp -O2 -std=c++14 -static -Wall
./a.out < subway1.in > subway.out
diff subway.out subway1.ans -Z -B
./a.out < subway2.in > subway.out
diff subway.out subway2.ans -Z -B
./a.out < subway3.in > subway.out
diff subway.out subway3.ans -Z -B
./a.out < subway4.in > subway.out
diff subway.out subway4.ans -Z -B
./a.out < subway5.in > subway.out
diff subway.out subway5.ans -Z -B
./a.out < subway6.in > subway.out
diff subway.out subway6.ans -Z -B
./a.out < subway7.in > subway.out
diff subway.out subway7.ans -Z -B

*/