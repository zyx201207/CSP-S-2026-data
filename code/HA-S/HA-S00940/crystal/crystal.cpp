#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
namespace Callisto{
	const ll N = 5e5+10, INF = 1e18;
	ll n, m, a[N], b[N], ans;
	
	ll getnum(int x, int y){
		ll t = a[y]*(y-x+1);
		return t-(b[y]-b[x-1]);
	}
	
	signed main(){
		freopen("crystal.in", "r", stdin);
		freopen("crystal.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(0), cout.tie(0);
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1, a+1+n);
		for(int i = 1; i <= n; i++){
			b[i] = b[i-1]+a[i];
		}
		for(int i = 1, j = 1; i <= n && j <= n; i++){
			while(getnum(j, i) > m){
				j++;
			}
			ans = max(ans, 1ll*(i-j+1));
		}
		cout << ans;
		return 0;
	}
}

signed main(){
	Callisto::main();
	return 0;
}




/*
3:10 T1读错题了，终于过了
4:30 T2 baoli
*/