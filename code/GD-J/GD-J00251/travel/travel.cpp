#include <bits/stdc++.h>
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;

std::string a, b, c, d;

template<typename T> bool in_range(T x, T a, T b)
	{
		return x >= a && x <= b;
	}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::cin >> a >> b >> c >> d;
	if (a == c) putchar('1');
	else return puts("0000"), 0;
	if (b.substr(0, 2) == d.substr(0, 2)) putchar('1');
	else return puts("000"), 0;
	if ((in_range(b[2], 'A', 'C') && in_range(d[2], 'A', 'C')) || (in_range(b[2], 'D', 'F') && in_range(d[2], 'D', 'F'))) putchar('1');
	else return puts("00"), 0;
	if (b[2] < d[2]) std::swap(b[2], d[2]);
	if ((b[2] - d[2] == 1 && b[2] != 'D') || (b[2] - d[2] == 2 && b[2] == 'F')) putchar('1');
	else return puts("0"), 0;
}
