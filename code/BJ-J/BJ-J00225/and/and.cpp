#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

ll n , m , a[N] , res;
bool st[N];

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i) cin >> a[i];
	for(int i = 1 ; i <= n ; ++ i) st[i] = 1;
	
	ll base = (1ll << 30);
	while(base)
	{
		int tot = 0;
		for(int i = 1 ; i <= n ; ++ i) if(st[i] && (a[i] & base))
			++ tot;
		if(tot >= m)
		{
			res += base;
			for(int i = 1 ; i <= n ; ++ i)
				if(!(a[i] & base))
					st[i] = 0;
		}
		base >>= 1;
	}
	
	cout << res << '\n';
	
	return 0;
}
/*
5 3
31 3 1 15 7
*/
