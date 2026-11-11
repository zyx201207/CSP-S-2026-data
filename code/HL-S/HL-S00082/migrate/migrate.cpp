#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;

ll c, t;
ll n, d, x[N];
vector<ll> mapp[N];
ll vis[N], vis1[N], vis2[N];//断点 起点 终点 
ll ans;
ll use1[N], use2[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(ll i = 1; i <= n; i++){
			cin >> x[i];
		}
		for(ll u = 1; u <= n; u++){
			for(ll v = u + 1; v <= n; v++){
				if(x[v] - x[u] <= d){
					mapp[u].push_back(v);
				}
			}
		}
		for(ll u = 1; u <= n - 4 + 1; u++){//路径标记 
			if(mapp[u].size() == 2 && mapp[u + 1].size() == 2){
				vis1[u] = 1;
				vis2[u + 3] = 1;
			}
		}
		for(ll u = 1; u <= n; u++){//断点 
			if(mapp[u].size() > 2){
				vis[u] = 1;
			}
			if(mapp[u].size() == 0){
				vis[u] = 1;
			}
			if(vis1[u] == 1){
				bool flag = 0;
				for(ll i = max(1LL * 1, u - 4 + 1); i < u; i++){
					if(vis1[i] == 1){
						//cout << "!\n";
						flag = 1;
					}
				}
				if(flag == 1){
					use1[u] = 1; 
				}
			}
			if(vis2[u] == 1){
				bool flag = 0;
				for(ll i = u + 1; i <= min(n, u + 4 - 1); i++){
					if(vis2[i] == 1){
						//cout << "!\n";
						flag = 1;
					}
				}
				if(flag == 1){
					use2[u] = 1;
				}	
			}
		}
		for(ll u = 1; u <= n; u++){
			if(vis1[u] == 1){
				ll i = u;
				ll cnt1 = 0;
				while(!vis[i] && i >= 1){
					cnt1++;
					i--;	
				}
				if(use1[u]){
					;
				}
				else{
					use1[u] = cnt1;	
				}
			}
			if(vis2[u] == 1){
				ll i = u;
				ll cnt2 = 0;
				while(!vis[i] && i <= n){
					cnt2++;
					i++;	
				}
				if(use2[u]){
					;
				}
				else{
					use2[u] = cnt2;	
				}
				if(mapp[i].size() == 0){
					cnt2++;
				}
				use2[u] = cnt2;
			}
		}
//		for(int i = 1; i <= n; i++){
//			cout << mapp[i].size() << " ";
//		}
//		cout <<endl;
//		for(int i = 1; i <= n; i++){
//			cout << vis1[i] << " ";
//		}
//		cout <<endl;
//		for(int i = 1; i <= n; i++){
//			cout << vis2[i] << " ";
//		}
//		cout <<endl;
//		for(int i = 1; i <= n; i++){
//			cout << vis[i] << " ";
//		}
//		cout <<endl;
//		for(int i = 1; i <= n; i++){
//			cout << use1[i] << " ";
//		}
//		cout <<endl;
//		for(int i = 1; i <= n; i++){
//			cout << use2[i] << " ";
//		}
//		cout <<endl;
		for(int u = 1; u <= n; u++){
			if(vis1[u] == 1){
				ans += use1[u] * use2[u + 3];
			}
		}
		cout << ans << "\n";
	}	
	return 0;
}
