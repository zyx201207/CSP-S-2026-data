#include <bits/stdc++.h>
#define vc(i, j, k) for (int i(j), vc##i(k + 1); i < vc##i; ++i)
#define cv(i, j, k) for (int i(j), vc##i(k - 1); i > vc##i; --i)
using ll = long long;
using pii = std::pair<int, int>;
using plc =std::pair<ll, char>;

ll read()
{
	ll x = 0; bool f = false;
	char ch = getchar();
	while (!isdigit(ch)) f = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
	if (f) x = ~x + 1;
	return x;
}

char gc()
{
	char ch = getchar();
	while (ch == ' ' || ch == '\n') ch = getchar();
	return ch;
}

const int N = 200000 + 5;
int n; ll tot = 0, ans = 0;
plc a[N];
std::vector<plc > vect;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	n = read();
	vc(i, 1, n) a[i] = {read(), gc()}, tot += a[i].first;
	bool flag = false;
	ll s = 0;
	vc(i, 1, n)
	{
		if (!flag && s + a[i].first > (tot - 1) / 2)
			if (tot & 1) 
			{
				flag = true;
				if (tot - 1 != 2 * s) vect.emplace_back((tot - 1) / 2 - s, a[i].second);
				if (s + a[i].first != (tot + 1) / 2) vect.emplace_back(s + a[i].first - (tot + 1) / 2, a[i].second);
			}
			else 
			{
				flag = true;
				if (tot != 2 * s) vect.emplace_back(tot / 2 - s, a[i].second);
				if (s + a[i].first != tot / 2) vect.emplace_back(s + a[i].first - tot / 2, a[i].second);	
			}
		else vect.push_back(a[i]), s += a[i].first;
	}
	int siz = vect.size(), p; ll qwq = 0;
	vc(i, 0, siz - 1) 
		if (qwq + vect[i].first == tot / 2) 
		{
			p = i;
			break;
		} else qwq += vect[i].first;
	cv(i, p, 0)
	{
		int j = p + 1; ll need = 0;
		for (; j < siz; ++j)
		{
			if (!vect[i].first) break;
			ll qwq = std::min(vect[i].first, vect[j].first);
			if (vect[i].second != vect[j].second) need += qwq;
			vect[i].first -= qwq, vect[j].first -= qwq;
		}
		ans += need;
	}
	std::cout << ans << '\n';
}

