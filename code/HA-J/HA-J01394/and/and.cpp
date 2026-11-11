#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;

ll n, m, xmax = -1, result;
pair<string, ll> p[(ll)(2ll * 1e5 + 10)];

string get_2(ll num)
{
	string res;
	do
	{
		res += num % 2 + '0';
		num /= 2;
	}while(num > 0);
	reverse(res.begin(), res.end());
	return res;
}

bool cmp(pair<string, ll> p1, pair<string, ll> p2)
{
	return p1.first > p2.first;
}

int main()
{
 	freopen("and.in", "r", stdin);
 	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)
	{
		cin >> p[i].second;
		p[i].first = get_2(p[i].second);
	}
	sort(p + 1, p + 1 + n, cmp);
	result = p[1].second;
	for(ll i = 2; i <= m; i++)
	{
		result &= p[i].second;
	}
	cout << result;
	
	return 0;
}

/*
有问题：and4对不上 。and4.in是连续数。 
*/

