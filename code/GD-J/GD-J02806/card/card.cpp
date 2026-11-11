#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10;

ll n, m, a[N], dp[N];

struct node{
	ll jud, o;
}d[N];
int main() {
	freopen("card.in","r", stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= m; i++) dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		ll sum = 0;
		for (int j = i; j <= n; j++) {
			d[j].o = a[j], sum++;
			for (int x = 1; x <= sum; x++) {
				if (d[j].o == d[x].o && !d[x].jud) {
					for (int y = x + 1; y <= sum; j++) 
						d[y].jud = 1;
				}
			}
			
		}
		
		for (int i = 1; i <= n; i++) {
			if (d[i].jud == 0) dp[i]++;
		}
	}
	
	for (int i = 1; i <= m; i++) cout << dp[i] << " ";
	return 0;
}
