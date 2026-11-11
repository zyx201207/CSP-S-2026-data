#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const ll N = 2e5 + 100;

ll ans = 0;
ll n, m;

ll r[N];

inline ll read() 
{
	ll x = 0;
	ll f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') 
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') 
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}


int main() 
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) 
	{
		r[i] = read();
	}
	
	sort(r + 1, r + n + 1);
	
	if (m == 1) 
	{
		cout << r[n];
		return 0;
	}
	if (m == 2) 
	{
		cout << (r[n] & r[n - 1]);
		return 0;
	}
	
	ans = r[n];
	ll times = m;
	for (int i = n - 1; i >= 1; i -- ) 
	{
		if (times == 1) 
		{
			break;
		}
		ans &= r[i];
		times -- ;
	}
	cout << ans;
}
