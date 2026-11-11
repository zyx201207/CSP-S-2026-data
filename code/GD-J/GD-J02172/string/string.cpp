#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
deque<pair<char, ll>>q;
int main()
{
	freopen("string6.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1;i <= n;i ++)
	{
		ll a;
		char c;
		scanf("%lld", &a);
		cin >> c;
		if (!q.empty() && q.back().first == c)
		{
			q.back().second += a;
		}
		else
		{
			q.push_back({c, a});
		}
	}
	ll ans = 0;
	while (!q.empty())
	{
		auto f = q.front();
		q.pop_front();
		if (q.empty()) break;
		auto b = q.back();
		q.pop_back();
		char fc = f.first, bc = b.first;
		ll fa = f.second, ba = b.second;
		if (fc == bc)
		{
			if (fa > ba) q.push_front({fc, fa - ba});
			else if (fa < ba) q.push_back({bc, ba - fa});
		}
		else
		{
			if (fa > ba) 
			{
				ans += ba;
				q.push_front({fc, fa - ba});
			}
			else if (fa < ba)
			{
				ans += fa;
				q.push_back({bc, ba - fa});
			}
			else ans += fa;
		}
	}
	printf("%lld", ans);
	return 0;
}
