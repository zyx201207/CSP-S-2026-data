#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod=998244353,inf=0x3f3f3f3f3f3f3f3f;
const int N=2e6+10,M=2e5+10;
mt19937 rnd(random_device{}());
int tc,T;
namespace Anaxa{
    int f[N],g[N],a[N],n,d,Pre[N];
    void solve()
    {
        cin >> n >> d;
        int ans=0;
        for ( int i = 1 ; i <= n ; i++ )cin >> a[i];
        if(tc==11||tc==12)
        {
            // cerr << "Debug\n";
            for ( int i = n ; i ; i-- )a[i]-=a[1];
            int gc=a[2]-a[1];d/=gc;
            if(d<=1)return cout << 0 << endl,void();
            for ( int i = 1 ; i <= n ; i++ )a[i]/=gc;
            for ( int i = 1 ; i <= n ; i++ )assert(a[i]==i-1);
            cout << max(0ll,n-(d+d-1)) << endl;
            return;
        }
        for ( int i = 1 ; i <= n ; i++ )Pre[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
        for ( int i = 1 ; i <= n ; i++ )
        {
            for ( int j = 1 ; j <= n ; j++ )f[j]=inf,g[j]=0;
            f[i]=0,g[i]=1;
            for ( int j = i+1 ; j <= n ; j++ )
            {
                int pre=Pre[j];pre=max(pre,i);
                if(pre==j)break;
                f[j]=f[pre]+1,g[j]=g[pre];
                pre++;
                while(pre<j&&f[pre]+1==f[j])
                {
                    g[j]+=g[pre++];
                    if(g[j]>2)break;
                }
                ans+=(g[j]==2);
            }
        }
        cout << ans << endl;
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	Anaxa::main();
	return 0;
}
/*
首先 $O(n^2)$ 的暴力是简单的。枚举一个起点然后设 $f_x$ 表示第 $i$ 个点到起点的最短路，$g_i$ 表示个数。递推即可。
我们先试图找一些性质？
断言：分岔只可能是 x1->x2->x4/x1->x3->x4 两条路径
试图进行证明。
假设存在这样的路径：
u->x1->x2->v
u->x3->x4->v
x3->x2,x1->x4 必然有至少一个合法，如此就有至少三条最短路。更长的路径同理。
那么一个合法点对的结构就比较显明了。
u->...->u'->x1->v'->...->v
u->...->u'->x2->v'->...->v
拆成了三部分：唯一路径的 u->u'，唯一路径的 v'->v，恰好两条路径的 u'->v'
我们先来分析两条路径部分的结构。[r-d,l+d] 范围内有恰好两个岛屿。
这两个岛屿显然必然相邻，一共有 $O(n)$ 对相邻岛屿，每对限制了一个 l 的区间和 r 的区间。只要你 l,r 在这个区间你就是一组合法的。
对于 u'->v' 的刻画暂时到这里为之。现在我们试图刻画恰好有一条最短路的情况。应该是从左到右贪和从右到左贪路径相同就可以了
但是这个刻画很难受啊
好吧看来我们的目标就是求出每个点作为起点/终点有多少个终点/起点仅有一条最短路。就拿求出来的 $O(n)$ 个区间对乱做了。
好吧没那么简单，我们面临一个严峻的问题：你凭什么认为 u->v 的路径一定会过 u',v'？
好吧我们先对性质投入思考。A 性质的话我们可以先每个点坐标以及 d 除以公差，然后如果两点距离是 2d-1 就是一对合法的，否则一定非法。
唉，还剩下 1.5h 直接写暴力了。
48pts
*/
/*
g++ migrate.cpp -O2 -std=c++14 -static
./a.out < migrate1.in > migrate.out
diff migrate.out migrate1.ans -Z -B
./a.out < migrate2.in > migrate.out
diff migrate.out migrate2.ans -Z -B
./a.out < migrate3.in > migrate.out
diff migrate.out migrate3.ans -Z -B
./a.out < migrate4.in > migrate.out
diff migrate.out migrate4.ans -Z -B
*/