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
const int N = 2e5 + 5, LGV = 30;
int n, m;
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	vector<int> now;
	for (int i = 1;i <= n;i++)
	{
		int a = read();
		now.eb(a);
	}
	int ans = 0;
	for (int j = LGV;j >= 0;j--)
	{
		vector<int> tmp;
		for (int i : now)
		{
			if ((1LL << j) & i) tmp.eb(i);
		}
		if (tmp.size() >= m)
		{
			ans += (1LL << j);
			now = tmp;
		}
	}
	write(ans);
	return 0;
}

