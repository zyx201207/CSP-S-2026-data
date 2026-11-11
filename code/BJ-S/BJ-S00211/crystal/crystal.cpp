#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

ll n , m , a[N] , s[N] , res;

bool check(int i , int x)	//from  x  to  i
{
	ll tot = s[i] - s[x - 1];
	ll len = i - x + 1;
	tot = len * a[i] - tot;
	return (tot <= m);
}

int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i) cin >> a[i];
	
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; ++ i) s[i] = s[i - 1] + a[i];
	
	for(int i = 1 ; i <= n ; ++ i)
	{
		int l = 1 , r = i;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(i , mid)) r = mid;
			else l = mid + 1;
		}
		res = max(res , i - l + 1ll);
	}
	
	cout << res << '\n';
	
	return 0;
}
