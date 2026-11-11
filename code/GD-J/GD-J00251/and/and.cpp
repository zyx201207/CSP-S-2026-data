#include <bits/stdc++.h>
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;
using psi = std::pair<std::string, int>;

ll read()
{
	ll x = 0; bool f = false;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
	if (f) x = ~x + 1;
	return x;
}

const int N = 200000 + 5;
int n, k, max, ad = (1ll << 32) - 1;
int a[N], c[5];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), k = read();
	vc(i, 1, n) 
	{
		max = std::max(max, a[i] = (int)read());
		ad &= a[i];
		if (a[i] < 4) ++c[a[i]];
	}
	if (max < 4) 
	{
		if (c[3] > k) std::cout << 3 << '\n';
		else if (c[3] + c[2] > k) std::cout << 2 << '\n';
		else if (c[3] + c[2] + c[1] > k) std::cout << 1 << '\n';
		else std::cout << 0 << '\n';
		return 0;
	}
	if (k == 1) return std::cout << max << '\n', 0;
	if (k == n) return std::cout << ad << '\n', 0;
	if (k == 2)
	{
		int max = -1;
		vc(i, 1, n) vc(j, 1, n) if (i != j)
			max = std::max(max, a[i] & a[j]);
		return std::cout << max << '\n', 0;
	}
	if (n < 21)
	{
		int max = -1;
		vc(i, 0, (1 << n) - 1)
		{
			int ad = (1ll << 32) - 1;
			std::vector<int> chos;
			vc(j, 0, n) if (i & (1 << j)) chos.push_back(j + 1);
			if (chos.size() != k) continue;
			vc(_, 0, k - 1) ad &= a[chos[_]];
			max = std::max(max, ad);
		}
		return std::cout << max << '\n', 0;
	}
}
