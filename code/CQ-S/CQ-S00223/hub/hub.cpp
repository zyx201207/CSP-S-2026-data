// 看我超大常数过掉 T3（本机过了，CCF 机子不知道……）
/*
现在考虑比较牛的假算。最好是能多过点测试点。

先考虑多项式时间正确做法。

二分。考虑 check。

f[u][0/1][0/1]: 考虑 u 的子树，u 本身选择/不选，这是第几个连通块，需要的最少点数。

转移？

如果 u 选了，那么考虑 u 的每个儿子；如果它也选了那就是选了。否则：

- 如果子树本就满足条件：无贡献。
- 如果子树不满足条件：剩下的一个连通块必然在里面。枚举其根节点。

然后这是 O(n^2) 的，加上二分能拿下 O(n^2 log n)。换句话说常数优秀的话有 50pts。

等等那你就 350？

考虑 k=2，此时对偶优化。

等等……不行。

考虑 k=2，此时模拟退火。

(退烧神人)

算了先不用乱搞骗分，先写 50pts 暴力，然后把前面题拍一下。
*/
/*
考虑如何判定？

u 本身覆盖了一部分。所以……嗯……

对，然后就可行了……？

等等……

还需要树上差分一下，不过可以接受。ok.

不好，写不完了，紧急回退到 30pts。

草，又写挂了，紧急回退到 15pts。
*/
// 怎么 T2 出现了两次更正，还有一次在最后 40min。草台班子比赛。草台子比赛。草台比赛。草比赛。【数据删除】。比。。
#include <queue>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const auto U = [](auto x) { return [x](auto ...y) { return x(x, y...); }; };

vector<int> web[1005];
int dst[1005][1005];
bitset<1005> bs;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int t;
	scanf("%*d%d", &t);
	while(t--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i=1;i<=n;i++)
		{
			web[i].clear();
			for(int j=1;j<=n;j++)
			{
				dst[i][j] = 0x3f3f3f3f;
			}
			dst[i][i] = 0;
		}
		for(int i=2;i<=n;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			web[u].push_back(v);
			web[v].push_back(u);
			dst[u][v] = 1; dst[v][u] = 1;
		}
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(dst[i][k] + dst[k][j] < dst[i][j]) dst[i][j] = dst[i][k] + dst[k][j];
		int ans = 0x3f3f3f3f;
		for(int msk=0;msk<(1<<n);msk++)
		{
			if(__builtin_popcount(msk) != k) continue;
			int cc = 0;
			for(int i=1;i<=n;i++) bs[i] = (msk & (1 << (i-1))) > 0;
			for(int i=1;i<=n;i++) if(bs[i])
			{
				U([&](auto &&self, int u) -> void { bs[u] = false; for(int v : web[u]) if(bs[v]) self(self, v); })(i);
				cc++;
			}
			if(cc > 2) continue;
			int maxn = 0;
			for(int i=1;i<=n;i++)
			{
				int minn = 0x3f3f3f3f;
				for(int j=1;j<=n;j++)
				{
					if(msk&(1<<(j-1))) minn = min(minn, dst[i][j]);
				}
				maxn = max(maxn, minn);
			}
			ans = min(ans, maxn);
		}
		printf("%d\n", ans);
	}
	return 0;
}