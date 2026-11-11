#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m, tot, ans, a[N], sx[N], scnt[N];
struct node
{
	int x, cnt;
} b[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	stable_sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] != a[i - 1]) b[++tot] = {a[i], 1};
		else ++b[tot]. cnt;
	}
	for (int i = 1; i <= tot; ++i) sx[i] = sx[i - 1] + b[i]. x * b[i]. cnt;
	for (int i = 1; i <= tot; ++i) scnt[i] = scnt[i - 1] + b[i]. cnt;
//	for (int i = 1; i <= tot; ++i) cout << b[i]. x << ' ' << b[i]. cnt << endl;
	for (int i = 1; i <= tot; ++i)
	{
		if (scnt[i - 1] * b[i]. x - sx[i - 1] <= m) ans = max(ans, scnt[i]);
		else
		{
			int l = 1, r = i - 1, res = -1;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				if ((scnt[i - 1] - scnt[mid - 1]) * b[i]. x - (sx[i - 1] - sx[mid - 1]) <= m) res = mid, r = mid - 1;
				else l = mid + 1;
			}
			if (res != -1)
			{
				int lft = m - ((scnt[i - 1] - scnt[res - 1]) * b[i]. x - (sx[i - 1] - sx[res - 1]));
				int pos = res, tmp = 0;
				while (lft >= (b[i]. x - b[pos - 1]. x))
				{
					int t = min(lft / (b[i]. x - b[pos - 1]. x), b[pos - 1]. cnt);
					lft -= t * (b[i]. x - b[pos - 1]. x);
					tmp += t;
					--pos;
					if (!pos) break;
				}
				ans = max(ans, scnt[i] - scnt[res - 1] + tmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

//5 8
//-3 -1 2 2 7

//5 5
//1 2 4 8 9
