#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ll long long

int n;
map < pair < int , int > , char >  str;
vector < pair < int , ll > > _pos;
map < int , ll > pos;

string s;

pair < int , int > find(ll idx)
{
	for (int i = 0; i + 1 < pos.size(); i += 2)
	{
		if (_pos[i].se <= idx && idx <= _pos[i + 1].se) 
		{
			return {_pos[i].fi, _pos[i + 1].fi};
		}
	}
	return {0, 0};
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	ll cur = 1, len = 0;
	ll ha_c = 1;
	int sum = 0;
	
	for (int i = 1; i <= n; i++)
	{
		int l;
		char c;
		cin >> l >> c;
		
		pos[ha_c] = cur;
		pos[ha_c + 1] = cur + l - 1;
		
		_pos.emplace_back(ha_c, cur);
		_pos.emplace_back(ha_c + 1, cur + l - 1);
		
		str[{ha_c, ha_c + 1}] = c;
		
		ha_c += 2;
		cur += l;
		len += l;
		
		for (int j = 1; j <= l; j++)
			s += c;
	}
	
	ll ans = 0;
	
	if (len <= 1ll * 2e5 * 500)
	{
		for (int i = 1, j = len; i <= j; i++, j--)
		{
			if (s[i] != s[j])
			{
				ans ++;
			}
		}
	}
	else 
	{

		for (ll i = 1, j = len; i <= j;)
		{
			auto u = find(i), v = find(j);
			if (u.se < len - v.fi)
			{
				while (1)
				{
					if (str[v] != str[u])
						ans += u.se - u.fi + 1;
					if (u.se >= len - v.fi)
						break;
				}
			}
			if (u.se > len - v.fi)
			{
				while (1)
				{
					if (str[v] != str[u])
						ans += v.se - v.fi + 1;
					if (u.se <= len - v.fi)
						break;
				}
			}
			if (u.se == len - v.fi)
			{
				u = find(u.se + 1), v = find(v.fi - 1);
			}
		}

	
	}
	
	cout << ans << endl;
	
	return 0;
}
