#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 1e9;
int dp[N], f[N], tr1[N * 4], tr2[N * 4], a[N], b[N];

void pushup(int p)
{
	if (tr1[p * 2] == tr1[p * 2 + 1]) tr2[p] = tr2[p * 2] + tr2[p * 2 + 1];
	else if (tr1[p * 2] < tr1[p * 2 + 1]) tr2[p] = tr2[p * 2];
	else tr2[p] = tr2[p * 2 + 1]; // 记录最短路方案数 
	tr1[p] = min(tr1[p * 2], tr1[p * 2 + 1]); // 记录最短路 
}

void build(int s, int t, int p)
{
	tr1[p] = tr2[p] = inf;
	if (s == t) return;
	int mid = s + (t - s) / 2;
	build(s, mid, p * 2);
	build(mid + 1, t, p * 2 + 1);
}

void fix(int s, int t, int fixpos, int p, int val, int cntsol)
{
	if (s == fixpos && t == fixpos)
	{
		if (tr1[p] > val) // 需要更新 
		{
			tr1[p] = val;
			tr2[p] = cntsol; 
		}
		return;
	}
	int mid = s + (t - s) / 2;
	if (fixpos <= mid) fix(s, mid, fixpos, p * 2, val, cntsol);
	if (fixpos > mid) fix(mid + 1, t, fixpos, p * 2 + 1, val, cntsol);
	pushup(p);
}

pair<int, int> query(int s, int t, int l, int r, int p)
{
	if (l <= s && t <= r) return {tr1[p], tr2[p]};
	int mid = s + (t - s) / 2;
	pair<int, int> tmp1 = {inf, inf}, tmp2 = {inf, inf};
	if (l <= mid) tmp1 = query(s, mid, l, r, p * 2);
	if (r > mid) tmp2 = query(mid + 1, t, l, r, p * 2 + 1);
	if (tmp1.first == tmp2.first) return {tmp1.first, tmp2.second + tmp1.second};
	if (tmp1.first < tmp2.first) return tmp1;
	return tmp2;
}

int getID(int x, int n)
{
	int idx = lower_bound(b + 1, b + n + 1, x) - b;
	return idx;
}

void init(int st, int ed)
{
	for (int j = 1, i = st; i <= ed; i++, j++)
	{
		b[j] = a[i];
		dp[j] = f[j] = inf;
	}
	build(1, ed - st + 1, 1);
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int C, T;
	cin >> C >> T;
	
	while (T--)
	{
		int n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
		for (int st = 1; st < n; st++) 
		{
			int len = n - st + 1;
			init(st, n);
			dp[1] = 0; f[1] = 1;
			fix(1, len, 1, 1, dp[1], f[1]);
			
			for (int i = 2; i <= len; i++)
			{
				int idx = getID(b[i] - d, len);
				pair<int, int> tmp = query(1, len, idx, i - 1, 1); 
				
				if (tmp.first < dp[i])
				{
					dp[i] = tmp.first + 1;
					f[i] = tmp.second;
					fix(1, len, i, 1, dp[i], f[i]);
				}
			}
			
			for (int i = 2; i <= len; i++) if (f[i] == 2) ans++;
		}
		cout << ans << "\n";
	}
	
	return 0;
}


