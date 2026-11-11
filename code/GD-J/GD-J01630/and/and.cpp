#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,ans;
bool a[35][20005];
ll num[200005];

bool cmp(ll x,ll y)
{
	return x > y;
}

int main()
{

	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	
	
	for(int i = 1;i <= n;i++)
	{
		ll x;
		cin >> x;
		num[i] = x;
	}
	
	/*
	ÃÜÂë£ºTrick||Treat!
	4 2
	3 15 12 12 
	*/
	sort(num + 1,num + n + 1,cmp);
	
	ll ans = 2147483647;
	
	for(int i = 1;i <= m;i++)
	{
		ans &= num[i];
		//cout << ans << '\n'; 
	}
	cout << ans;
	
	return 0;
}
