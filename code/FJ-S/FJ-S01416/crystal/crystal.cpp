#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 5e5 + 5;
ll a[MAXN];
int n;
ll m;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	freopen("crystal.err", "w", stderr);
	
//	auto start = time(0);
	
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	int ans = 0;
	ll last = a[1];
	for (int i = 2; i <= n; i++)
	{
		ll diff = (a[i] - last) * (i - 1ll);
//		cerr << "diff=" << diff << "   m=" << m << endl;
		if (diff <= m)
		{
			last = a[i];
			ans = i;
			m -= diff; 
		}
		else
		{
			break;
		}
	}
	
//	auto end = time(0);
//	cerr << "start at " << start << "  end at " << end << endl;
	
	cout << ans << endl;
	return 0;
 } 
