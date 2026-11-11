#include <bits/stdc++.h>
using namespace std;
const int N = 1e+4;
long long c,n,m,d,q;
long long w[N],a[N],t[N];
long long ans = 0;

int main()
{
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1 ; i <= m ; i++)
	{
		cin >> w[i];
	}
	for (long long i = 1 ; i <= n ; i++)
	{
		for (long long j = 1 ; i <= 7 ; i++)
		{
			cin >> a[i][j];
		}
	}
	
	
	cout << ans;
	return 0;
}
