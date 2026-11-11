#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+5
ll n, m, a[maxn], s[maxn];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i-1] & a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j <= i; j <= m; j++)
		{
			
		}
	}

	return 0;
}
