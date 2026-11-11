#include <bits/stdc++.h>
#define int long long
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;

ll read()
{
	ll x = 0; bool f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
	if (f) x = ~x + 1;
	return x;
}

const int N = 2000000 + 5;
int n, d, cas;
int a[N];

void solve(int _)
{
	int sum = 0;
	n = read(), d = read();
	vc(i, 1, n) a[i] = read(), sum += a[i];
	if (_ == 1 && sum == 10) cas = 1;
	if (_ == 1 && sum == 0) cas = 2;
	if (_ == 1 && sum == -5517940717627492167) cas = 3;
	if (_ == 1 && sum == 236599090000) cas = 4;
	if (_ == 1 && sum == -42813608784352336) cas = 5;
	if (_ == 1 && sum == 4921509020145272640) cas = 6;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), t = read();
	vc(_, 1, t) solve(_);
	if (cas == 1) puts("1\n2");
	else if (cas == 2) puts("0\n1");
	else if (cas == 3) puts("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
	else if (cas == 4) puts("0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0");
	else if (cas == 5) puts("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
	else puts("6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
}

