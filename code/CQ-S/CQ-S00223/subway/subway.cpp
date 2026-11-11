/*
骗你的，我在 10min 内读错了两次题面。n,m 看反说是。到底谁在用 m 表示点数 n 表示边数啊？

首先 w 显然是没用的。

然后建图，对于每个线路只建一个点，然后跑单源最短路。

……但是你存不下来，500 * 500000 * 4 达到了 900+，随便再多点东西就 ML 了。

描述一下，图是二分图且有一边点数少，另一边度数小，多次询问两个点之间的最短路。

如果 d=2，相当于在点数少的那边连边！

那么 d=20，也就是连边！就是 20 * 19 / 2 = 190 条而已。

那么 500^3 跑全源最短路完全可行！

对于询问呢？

每次枚举对应的两个点，O(qd^2)。

最终复杂度就是，O(nd^2 + n^3 + qd^2)，非常可做！
*/
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

vector<pair<int, long long>> wsx[500005]; // 挑战每个题都用 wsx 作为变量名。
long long dst[505][505];
long long w[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n, m, q;
	scanf("%*d%d%d%*d%d", &n, &m, &q);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld", w + i);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d", &k);
		while(k--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			wsx[x].push_back({i, y});
		}
	}
	memset(dst, 0x3f, sizeof dst);
	for(int i=1;i<=n;i++) dst[i][i] = 0;
	for(int i=1;i<=m;i++)
	{
		for(const auto &[a, x] : wsx[i])
		{
			for(const auto &[b, y] : wsx[i])
			{
				if(a != b) dst[a][b] = min(dst[a][b], x + y);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}
	while(q--)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		long long minn = 0x3f3f3f3f3f3f3f3f;
		for(const auto &[a, x] : wsx[s])
		{
			for(const auto &[b, y] : wsx[t])
			{
				minn = min(minn, x + y + dst[a][b]);
			}
		}
		printf("%lld\n", minn + w[s] + w[t]);
	}
	return 0;
}
/*
感受一下 sanitize?

$ g++ -std=c++14 -Wall -Wextra -Wpedantic -Wshadow -Wconversion -Wno-sign-compare -fsanitize=undefined,address -lm ./subway.cpp -o ./subway -g
$ i=4
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m2.861s
user	0m2.820s
sys	0m0.026s # T 了，好慌
$ i=5
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m2.814s
user	0m2.785s
sys	0m0.025s
$ i=6
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m3.314s
user	0m3.267s
sys	0m0.036s
$ i=7
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m3.376s
user	0m3.283s
sys	0m0.052s

$ g++ -std=c++14 -static ./subway.cpp -o ./subway -O2
$ i=4
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m0.117s
user	0m0.092s
sys	0m0.016s
$ i=5
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m0.093s
user	0m0.080s
sys	0m0.012s
$ i=6
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m0.222s
user	0m0.203s
sys	0m0.008s
$ i=7
$ cp ../down/subway/subway$i.in ./subway.in; time ./subway; diff -Z ./subway.out ../down/subway/subway$i.ans

real	0m0.257s
user	0m0.216s
sys	0m0.024s

*/