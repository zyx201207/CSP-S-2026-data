#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N = 2e5 + 5;
ll n , m , a[N] , ans = -1;
void bfs(ll x , ll k , ll t)
{
	if(k <= ans && k != -1) return;
	if(t == 0)
	{
		ans = max(ans , k);
		return;
	}
	for(ll i = x ; i <= n - t + 1 ; i ++)
	{
		if(k == -1) bfs(i + 1 , a[i] , t - 1);
		else bfs(i + 1 , k & a[i] , t - 1);
	}
	return;
}
int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i ++) cin >> a[i];
	bfs(1 , -1 , m);
	cout << ans;
	return 0;
}
