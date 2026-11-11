#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll lowbit(ll x){
	return x & (-x);
}
ll lg(ll x){
	ll res = 0;
	while(x > 0){
		x /= 2;
		res++;
	}
	return res - 1;
}
int n , m;
ll a[N] , ans , maxx , sh;
bool bit[50][N] , vis[N];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> m;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		ll tmp = a[i];
		while(tmp > 0){
			ll t = lg(lowbit(tmp));
			maxx = max(t , maxx);
			bit[t][i] = 1;
			tmp -= lowbit(tmp);
		}
	}
	sh = n;
	for(int i = maxx;i >= 0;--i){
		ll res = 0;
		for(int j = 1;j <= n;++j){
			if(bit[i][j]){
				res++;
			}
		}
		if(res >= m){
			maxx = i;
			break;
		}
	}
	for(int i = maxx;i >= 0;--i){
		for(int j = 1;j <= n;++j){
			if(bit[i][j]) continue;
			if(!bit[i][j] && !vis[j]){
				sh--; 
				vis[j] = 1;
			}
			if(sh == m){
				bool f = 0;
				for(int k = 1;k <= n;++k){
					if(!vis[k]){
						if(!f){
							ans = a[k];
							f = 1;
						}else{
							ans &= a[k];
						}
					}
				}
				cout << ans;
				return 0;
			}
		}
	}
	return 0;
}
