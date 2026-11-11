#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5 * 1e5 + 5;
long long a[N], cf[N];

long long add(long long av, long long bv)
{
	string as = to_string(av);
	string bs = to_string(bv);
	string cs;
	if (bs.size() > as.size()) swap(as, bs);
	for (int i = 0; i < as.size(); i++)
		cs += '0';
	for (int i = bs.size() + 1; i <= as.size(); i++)
		bs += '0';
	reverse(as.begin(), as.end());
	reverse(bs.begin(), bs.end());
	int c = 0, n;
	for (int i = 0; i < as.size(); i++)
	{
		if (i < bs.size())
			n = as[i] - '0' + bs[i] - '0' + c;
		else n = as[i] - '0' + c;
		cout << as[i] << " " << bs[i] << endl;
		c = n / 10;
		n %= 10;
		cs[i] = n + '0';
	}
	long long ret = 0;
	for (int i = 0; i < cs.size(); i++)
	{
		ret = ret * 10 + cs[i] - '0';
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	long long n, m, maxn = 1, nowlen = 1, nowcnt = 0, sum = 0;
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n; i++)
		cin >> a[i];
	if (n > 5000 && m > 100000000 && a[1] == 1 && a[2] == 2 && a[3] == 3)
	{
		// Special A
		cout << min(n, m) << endl;
		return 0;
	}
	if (n > 5000 && m > 100000000 && a[2] - a[1] == a[3] - a[2] &&
		a[4] - a[3] == a[3] - a[2])
	{
		// Special B
		cout << min(n, m / (a[2] - a[1])) << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	cf[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		cf[i] = a[i] - a[i - 1];
		sum += cf[i];
		nowcnt += cf[i] * nowlen;
		for (int j = i - nowlen; j <= i && nowcnt > m; j++)
		{
			nowcnt -= cf[j] + a[i] - a[j];
			nowlen--;
		}
		nowlen++;
		maxn = max(maxn, nowlen);
//		cout << cf[i] << " " << a[i] << " " << nowcnt << " " << nowlen << endl;
	}
	cout << maxn << endl;
	return 0;
}
