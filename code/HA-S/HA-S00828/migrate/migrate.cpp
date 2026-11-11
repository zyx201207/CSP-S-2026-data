#include <bits/stdc++.h>

using namespace std;

#define log(...) fprintf(stderr, __VA_ARGS__)

#define int long long
ifstream fin("migrate.in");
ofstream fout("migrate.out");
#define cin fin
#define cout fout

const int N = 2e6 + 10;

int n, c, d, x[N], nxt[N], f[N][2][2];

void solve()
{
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
//	for (int i = 1; i <= n; i++) cout << x[i] - x[i - 1] << ' '; cout << endl;
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (j < n && x[j + 1] - x[i] <= d) j++;
		if (j <= i) nxt[i] = -1;
		else nxt[i] = j;
	}
	x[0] = -3.1e18;
	
	for (int i = 1; i <= n; i++) memset(f[i], 0, sizeof f[i]);
	for (int p = n, k1 = n + 1, k2 = n + 1; p >= 2; p--)
	{
		while (k1 > p + 1 && x[k1 - 1] > d + x[p - 2]) k1--;
		while (k2 > p + 1 && x[k2 - 1] > d + x[p - 1]) k2--;
		if (nxt[p] == -1)
		{
			continue;
		}
		f[p][1][0] += max(0ll, nxt[p] - k2 + 1);
		f[p][0][0] += max(0ll, min(nxt[p] + 1, k2) - k1);
//		for (int i = p + 1; i <= nxt[p]; i++)
//			f[p][0][0] += (x[i] > d + x[p - 2] && x[i] <= d + x[p - 1]), f[p][1][0] += (x[i] > d + x[p - 1]);
		f[p][1][1] = f[p][1][0];
		if (x[nxt[p]] - x[p - 2] <= d) continue;
		int dc = x[nxt[p]] - x[p - 1] <= d, de = nxt[p] > p + 1 && x[nxt[p] - 1] - x[p - 1] <= d;
		if (dc) f[p][0][0] += f[nxt[p]][1][de], f[p][0][1] += f[nxt[p]][1][1];
		else f[p][0][0] += f[nxt[p]][0][de], f[p][1][0] += f[nxt[p]][1][de], f[p][0][1] += f[nxt[p]][0][1], f[p][1][1] += f[nxt[p]][1][1];
//		log("f(%lld) = %lld,%lld\n", p, f[p][0], f[p][1]);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		if (nxt[i] == -1) continue;
		if (nxt[i] >= i + 2) ans = f[nxt[i]][0][0];
		else 
		{
			if (nxt[nxt[i]] == -1) continue;
			int nxt2 = nxt[nxt[i]];
			ans = f[nxt2][x[nxt2] - x[nxt[i] - 1] <= d][nxt2 > nxt[i] + 1 && x[nxt2 - 1] - x[i] <= d];
		}
		ret += ans;
//		cout << ans << ' ';
	}
	cout << ret << '\n';
	
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		int p = i, c = 0;
//		for (int j = nxt[i] + 1; j <= n; j++)
//		{
//			if (nxt[p] < j) 
//			{
//				int lst = p;
//				p = nxt[p];
//				if (lst - 1 >= i && x[p] - x[lst - 1] <= d) c++;
//				if (lst - 2 >= i && x[p] - x[lst - 2] <= d) break;
//				if (c == 2) break;
//				if (nxt[p] == -1) break;
//			}
//			if (c)
//			{
//				ans += (x[j] - x[p - 1] > d);
////				if (x[j] - x[p - 1] > d) log("ty=1: i=%lld, j=%lld\n", i, j);
//			}
//			else if (p - 2 >= i)
//			{
//				ans += ((x[j] - x[p - 2] > d) && (x[j] - x[p - 1] <= d));
////				if ((p == 1 || x[j] - x[p - 2] > d) && (x[j] - x[p - 1] <= d) ) log("ty=2: i=%lld, j=%lld\n", i, j);
//			}
//		}
//	}
//	cout << ans << '\n';
}

signed main()
{
	int t; cin >> c >> t;
	while (t--) solve();
}

