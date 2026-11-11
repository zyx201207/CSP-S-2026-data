#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 250005;
const int M = 1505;
const int INF = 1e9;
const int mod = 998244353;
int a[N], vis[N];
void work(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 32; i >= 0; i--){
		int need = (1ll << i), sum = 0;
		for(int j = 1; j <= n; j++){
			if(vis[j] == 0 && (a[j] & need)){
				sum ++;
//				cout << i << " " << a[j] << "\n";
			}
		}
//		cout << need << " " << sum << "\n";
		if(sum >= m){
			for(int j = 1; j <= n; j++){
				if(vis[j] == 0 && (a[j] & need)){
					continue;
				}
				vis[j] = 1;
			}
			ans += need;
		}
	}
	cout << ans;
	return ;
}
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --){
		work();
	}
	return 0;
} 
//luogu uid:910628 球上神人共赏
