//T1,写的最快的一次
//思路有了，代码有了，接下来看noi评测机的了 
//时间复杂度O(n + nlogn + n~n*n)
//空间复杂度O(n + n)
//2026年10月31日15:06:16 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 5e5 + 9;;

ll n,m;
ll a[N];

ll cost;
ll ans;

deque<ll> q;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1,a + 1 + n);
	
	for(ll i = 1; i <= n; i++)
	{
		ll s = q.size();
		if(s != 0) cost += s * (a[i] - q.back());
		
		q.push_back(a[i]);
		
		while(cost > m)
		{
			cost -= a[i] - q.front();
			q.pop_front();
		}
		
		ans = max(ans,(ll)q.size());
	}
	
	cout << ans;
	return 0;
}

