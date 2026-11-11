#include <bits/stdc++.h>
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;

ll read()
{
	ll x = 0; bool f = false;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
	if (f) x = ~x + 1;
	return x;
}

const int N = 500000 + 5;
int n, m;
int a[N], c[N], vis[N];

void solve(int st)
{
	std::deque<int> dq;
	__builtin_memset(vis, 0, sizeof vis);
	vc(i, st, n)
	{
		if (!vis[a[i]]) dq.push_back(a[i]), vis[a[i]] = true;
		else while (dq.back() != a[i]) vis[dq.back()] = false, dq.pop_back();
	}
	while (!dq.empty()) ++c[dq.front()], dq.pop_front();
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	n = read(), m = read();
	vc(i, 1, n) a[i] = read();
	vc(i, 1, n) solve(i);
	vc(i, 1, m) std::cout << c[i] << ' ';
	std::cout << '\n';
}

