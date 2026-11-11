#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n;
ll x[N] , nxt[N] , d , cnt;
void dfs(int l , int r , int cur , int m){
	if(cnt > 2 || cur > m) return;
	if(l >= r){
		if(cur == m) cnt++;
		return;
	}
	for(int i = l ; i <= nxt[l] ; ++i){
		if(i > r) break;
		dfs(i , r , cur + 1 , m);
	}
}
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T;
	cin >> c >> T;
	while(T--){
		memset(nxt , 0 , sizeof nxt);
		cin >> n >> d;
		for(int i = 1 ; i <= n ; ++i) cin >> x[i];
		for(int i = 1 ; i <= n ; ++i){
			for(int j = i ; j <= n ; ++j){
				if(x[j] - x[i] <= d) nxt[i] = j;
				else break;
			}
		}
		int ans = 0;
		for(int l = 1 ; l <= n ; ++l){
			for(int r = l + 2 ; r <= n ; ++r){
				int p = l , m = 0;
				if(nxt[p] == 0) continue;
				while(x[p] < x[r]){
					m++;
					p = nxt[p];
				}
				cnt = 0;
				dfs(l , r , 0 , m);
				if(cnt == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
