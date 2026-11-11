#include <iomanip>
#include <iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int n;
struct fu
{
	int a, s;
	char c;
}h[N];

int findp(int x)
{
	int l = 1, r = n, ret = 0;
	while (l <= r)
	{
		int mid = l + ((r - l) >> 1);
		if (h[mid].s >= x)
		{
			ret = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ret;
}

int min(int a, int b)
{
	return (a < b ? a : b);
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i].a >> h[i].c;
		h[i].s = h[i - 1].s + h[i].a;
	}
	
	int ans = 0;
	int l = 1, r = h[n].s;
	while (l < r)
	{
		int lf = findp(l), rf = findp(r);
		if (lf == rf) break;
		int ls = h[lf].s - l + 1, rs = r - h[rf - 1].s;
		int t = min(ls, rs);
		if (h[lf].c != h[rf].c)
			ans += t;
		l += t;
		r -= t;
	}
	cout << ans;
	return 0;
}
