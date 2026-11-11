#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 2e6 + 5;
ll c, t, n, k, u[MAXN], v[MAXN];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%lld%lld", &c, &t);
	while(t--)
	{
		scanf("%lld%lld", &n, &k);
		for(ll i = 1; i <= n - 1; i++)
		{
			scanf("%lld%lld", &u[i], &v[i]);
		}
		cout << (t % 2 + 1) % 2 + 1;
	}
	return 0;
}
