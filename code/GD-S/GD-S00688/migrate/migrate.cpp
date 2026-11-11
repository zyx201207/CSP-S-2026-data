#include <bits/stdc++.h>
#define int long long
#define eb emplace_back
#define endl putchar('\n')
using namespace std;
int read()
{
	int sum = 0, f = 1;
	char ch = getchar();
	for (ch;ch < '0' || ch > '9';ch = getchar()) if (ch == '-') {f = -1;}
	for (ch;ch >= '0' && ch <= '9';ch = getchar()) sum = sum * 10 + ch - '0';
	return sum * f;
}
void write(int x)
{
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void gmax(int &x, int y)
{
	if (y > x) x = y;
}
void gmin(int &x, int y)
{
	if (y < x) x = y;
}
/*
考虑枚举起点，跑普通bfs，对每个点累计其经过次数cnt，满足cnt == 2即统计贡献 
*/
const int MAXN = 2e6 + 5, inf = 1e18;
int CID, T, n, d, a[MAXN];
bool checkA()
{
	int tmp = a[2] - a[1];
	for (int i = 2;i <= n;i++)
	{
		if (a[i] - a[i - 1] != tmp) return 0;
	}
	return 1;
}
//Forever Young & Happy
namespace ForeverYoungHappy//40pts
{
	const int N = 5e3 + 5;
	int dis[N], cnt[N];
	int oind[N], ind[N];
	int q[N];
	vector<int> vec[N]; 
	void work()
	{
		fill(oind + 1, oind + n + 1, 0);
		for (int i = 1;i <= n;i++) vec[i].clear();
		for (int u = 1;u <= n;u++)
		{
			for (int v = u + 1;v <= n;v++)
			{
				if (a[u] + d < a[v]) break;
				vec[u].eb(v);
				oind[v]++;
//				cout<<u<<" -> "<<v, endl;
			}
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			fill(cnt + i + 1, cnt + n + 1, 0);
			fill(dis + i + 1, dis + n + 1, inf);
			for (int j = i;j <= n;j++) ind[j] = oind[j];
			int head = 1, tail = 0;
			q[++tail] = i;
			cnt[i] = 1;
			dis[i] = 0;
			while (head <= tail)
			{
				int now = q[head++];
				for (int to : vec[now])
				{
					if (dis[now] + 1 < dis[to])
					{
						dis[to] = dis[now] + 1;
						cnt[to] = cnt[now];
					}
					else if (dis[now] + 1 == dis[to]) cnt[to] += cnt[now];
//					cout<<now<<" -> "<<to<<" : "<<ind[to], endl;
					if(!--ind[to]) q[++tail] = to;
				}
			}
//			cout<<i<<" : ", endl;
//			for (int j = i + 1;j <= n;j++) cout<<j<<" : "<<dis[j]<<" , "<<cnt[j], endl;
			for (int j = i + 1;j <= n;j++)
			{
				if (cnt[j] == 2) ans++;
			}
			for (int to : vec[i]) oind[to]--;
		}
		write(ans), endl;
//		endl;
	}
}
namespace subA//8pts
{
	void work()
	{
		int da = a[2] - a[1];
		int k = d / da;
		int ans = 0;
		if (k > 1)
		{
			int l = 1, r = n;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (mid + k + k - 1 <= n) ans = mid, l = mid + 1;
				else r = mid - 1;
			}
		}
		write(ans), endl;
	}
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	CID = read(), T = read();
	while (T--)
	{
		n = read(), d = read();
		for (int i = 1;i <= n;i++) a[i] = read();
		if (n == 1) puts("0");
		else if (checkA()) subA::work();
		else ForeverYoungHappy::work();
	}
	return 0;
}
