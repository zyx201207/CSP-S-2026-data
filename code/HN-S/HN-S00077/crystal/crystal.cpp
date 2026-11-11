#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 5e5 + 5;

ll a[NR], d[NR];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += abs(a[i]);
	}
	sum /= n;
	sort(a+1, a+n+1);
	int pos = 1;
	for(int i = 2; i < n; i++)
	{
		if(a[i] - a[i-1] > sum)
		{
			pos = i;
			break;
		}
	}
	for(int i = pos; i <= n; i++)
		d[i] = d[i-1] + (a[i] - a[i-1]) * (i - pos);
	for(ll i = pos; i < n; i++)
	{
		if(d[i+1] > m) 
		{
			cout << i - pos + 1;
			return 0;
		}
	}
	cout << n - pos + 1;
	return 0;
}

