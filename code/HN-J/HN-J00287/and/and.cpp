#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , ans;
int a[200005];
vector<int> s[35];
set<int> q;
signed main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		int w = 0 , x , p;
		cin >> x;
		q.insert(x);
		p = x;
		while(x)
		{
			if(x % 2)s[w].push_back(p);
			w ++;
			x /= 2;
		}
	}
	for(int i = 30; i >= 0; i --)
	{
		int js = 0;
		for(int j = 0; j < s[i].size(); j ++)
		{
			int t = s[i][j];
			if(q.find(t) != q.end())js ++;
		}
		if(js >= m)
		{
			ans += (1 << i);
			set<int> g;
			for(int j = 0; j < s[i].size(); j ++)
			{
				int t = s[i][j];
				if(q.find(t) != q.end())g.insert(t);
			}
			q = g;
		}
	}
	cout << ans;
	return 0;
}
