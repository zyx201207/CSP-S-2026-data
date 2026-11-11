// 中等题。
/*
几个方向：倍增，线段树优化建图。看起来倍增更有前途。

但是倍增怎么处理第二多呢？

这是简单的吧。先不管。

那这样就可以计算两个岛屿是否合法了。只需要一路跳过去，然后有恰好一个 2 且没有 >= 3 就合法。

如何计算合法数量？

这是好做的。

时间复杂度 O(n log n)，做完了。

倍增怎么做？

大分讨吗，看起来好复杂 :(。
*/
/*
我是空想派做题家。

000
001
011
012
xxx
0xx
00x
01x

ok that's it
*/
// 剩下的事情就是卡常了……
#include <cstdio>
#include <cassert>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

long long x[2000005];
class vstat { public: int a, b, c; } wsx[25][2000005];
long long dp[2000005][8];

char ibf[100000005];
unsigned li = 0;
unsigned quread() { unsigned res = 0; char ch; while((ch = ibf[li++]) < '0' || ch > '9'); do { res = res * 10 + ch - '0'; } while((ch = ibf[li++]) >= '0' && ch <= '9'); return res; }
long long qllread() { long long res = 0, fg = 1; char ch; while((ch = ibf[li++]) < '0' || ch > '9') if(ch == '-') fg = -1; do { res = res * 10 + ch - '0'; } while((ch = ibf[li++]) >= '0' && ch <= '9'); return res * fg; }

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fread(ibf, 1, sizeof ibf, stdin);
	int t;
	quread(); t = quread();
	auto tract74 = [](int p, int msk) -> vstat
	{
		switch(msk)
		{
			case 0: return {p, p, p};
			case 1: return {p, p, p+1};
			case 2: return {p, p+1, p+1};
			case 3: return {p, p+1, p+2};
			case 4: return {0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f};
			case 5: return {p, 0x3f3f3f3f, 0x3f3f3f3f};
			case 6: return {p, p, 0x3f3f3f3f};
			case 7: return {p, p+1, 0x3f3f3f3f};
			default: assert(false);
		};
	};
	auto tesseract = [](int a, int b, int c) -> int { if(c != 0x3f3f3f3f) return (int(a < b) << 1) | int(b < c); if(a == 0x3f3f3f3f) return 4; if(b == 0x3f3f3f3f) return 5; return a == b ? 6 : 7; };
	auto tractor = [&](int lvl, int id) -> vstat { if(id >= 0x3f3f3f3f) return {0x3f3f3f3f, 0x3f3f3f3f, 0x3f3f3f3f}; return wsx[lvl][id]; };
	while(t--)
	{
		int n;
		long long d;
		// scanf("%d%lld", &n, &d);
		n = quread(); d = qllread();
		int vl = 1;
		for(int i=1;i<=n;i++)
		{
			// scanf("%lld", x + i);
			x[i] = qllread();
			while(x[vl] < x[i] - d) vl++;
			wsx[0][i] = {vl, vl + 1 >= i ? 0x3f3f3f3f : vl + 1, vl + 2 >= i ? 0x3f3f3f3f : vl + 2};
			for(int j=1;(1<<j)<=n;j++)
			{
				auto [va, vb, vc] = wsx[j-1][i];
				auto [k1, k2, k3] = tractor(j-1, va);
				auto [b1, b2, b3] = tractor(j-1, vb);
				do
				{
					if(b1 < k1) { k3 = k2; k2 = k1; k1 = b1; if(b2 < k2) { k3 = k2; k2 = b2; if(b3 < k3) k3 = b3; } else if(b2 < k3) k3 = b2; else break; } else if(b1 < k2) { k3 = k2; k2 = b1; if(b2 < k3) k3 = b2; else break; } else if(b1 < k3) k3 = b1; else break;
				} while(false);
				auto [c1, c2, c3] = tractor(j-1, vc);
				do
				{
					if(c1 < k1) { k3 = k2; k2 = k1; k1 = c1; if(c2 < k2) { k3 = k2; k2 = c2; if(c3 < k3) k3 = c3; } else if(c2 < k3) k3 = c2; else break; } else if(c1 < k2) { k3 = k2; k2 = c1; if(c2 < k3) k3 = c2; else break; } else if(c1 < k3) k3 = c1; else break;
				} while(false);
				wsx[j][i] = {k1, k2, k3};
				// printf("wsx[%d][%d] = {%d, %d, %d} ({%d, %d, %d})\n", j, i, varr[0], varr[1], varr[2], wsx[j][i].r, wsx[j][i].ms, wsx[j][i].vci);
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(dp[i], 0, sizeof dp[i]);
			dp[i][5] = 1;
		}
		for(int j=__lg(n);j>=0;j--)
		{
			for(int i=1;i<=n;i++)
			{
				for(int x=0;x<8;x++)
				{
					if(!dp[i][x]) continue;
					auto [va, vb, vc] = tract74(i, x);
					auto [k1, k2, k3] = tractor(j, va);
					auto [b1, b2, b3] = tractor(j, vb);
					do
					{
						if(b1 < k1) { k3 = k2; k2 = k1; k1 = b1; if(b2 < k2) { k3 = k2; k2 = b2; if(b3 < k3) k3 = b3; } else if(b2 < k3) k3 = b2; else break; } else if(b1 < k2) { k3 = k2; k2 = b1; if(b2 < k3) k3 = b2; else break; } else if(b1 < k3) k3 = b1; else break;
					} while(false);
					auto [c1, c2, c3] = tractor(j, vc);
					do
					{
						if(c1 < k1) { k3 = k2; k2 = k1; k1 = c1; if(c2 < k2) { k3 = k2; k2 = c2; if(c3 < k3) k3 = c3; } else if(c2 < k3) k3 = c2; else break; } else if(c1 < k2) { k3 = k2; k2 = c1; if(c2 < k3) k3 = c2; else break; } else if(c1 < k3) k3 = c1; else break;
					} while(false);
					if(k1 >= 0x3f3f3f3f) continue;
					int vx = k1, vy = tesseract(k1, k2, k3);
					dp[vx][vy] += dp[i][x];
				}
			}
		}
		long long s = 0;
		for(int i=1;i<=n;i++)
		{
			for(int x=0;x<8;x++)
			{
				if(dp[i][x])
				{
					auto [a, b, c] = tract74(i, x);
					// printf("dp[%d][{%d, %d, %d} (x = %d, y = %d)] = %lld\n", i, a, b, c, x, y, dp[i][x][y]);
					if(a == b && b != c)
					{
						int vx = wsx[0][a].a, vy = (c >= 0x3f3f3f3f ? i : wsx[0][c].a);
						// (vx, vy) 之间的都可以
						s += dp[i][x] * (vy - vx);
					}
					else if(a != b && b < 0x3f3f3f3f)
					{
						int vy = wsx[0][b].a, vz = (c >= 0x3f3f3f3f ? i : wsx[0][c].a);
						s += dp[i][x] * (vz - vy);
					}
				}
			}
		}
		printf("%lld\n", s);
	}
	return 0;
}