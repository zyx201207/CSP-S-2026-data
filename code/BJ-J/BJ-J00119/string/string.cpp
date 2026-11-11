#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, char> pr;
typedef vector<pr> vp;

int f(vp v)
{
	int l = 0, r = v.size() - 1, ans = 0;
	while (l <= r)
	{
		if (v[l].second != v[r].second)
		{
			ans += min(v[l].first, v[r].first);
			if (v[l].first > v[r].first) v[l].first -= v[r--].first;
			else if (v[l].first < v[r].first) v[r].first -= v[l++].first;
			else
			{
				r--;
				l++;
			}
		}
		else
		{
			if (v[l].first > v[r].first) v[l].first -= v[r--].first;
			else if (v[l].first < v[r].first) v[r].first -= v[l++].first;
			else
			{
				r--;
				l++;
			}
		}
	}
	return ans;
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vp a;
	pr p;
	while (n--)
	{
		pr t;
		cin >> t.first >> t.second;
		if (t.second == p.second) p.first += t.first;
		else
		{
			a.push_back(p);
			p = t;
		}
	}
	a.push_back(p);
	cout << f(a) << endl;
//	unsigned long long my_rp = -1;
	
	return 0;
}