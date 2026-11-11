#include<bits/stdc++.h>
#define int long long
using namespace std;
int c , t , n , d;
vector<int> vec[500005];
int x[500005] , vis[500005] , dis[500005] , num[500005];
priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int , int> > > pq;  
signed main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++) cin >> x[i];
		if(n == 1){
			cout << "0\n";
			continue;
		}
		bool flag = true;
		for(int i = 3 ; i <= n ; i++){
			if(x[i] - x[i - 1] != x[2] - x[1]){
				flag = false;
				break;
			}
		}
		if(flag == true && n >= 500){
			int lo = d / (x[2] - x[1]);
			if(lo <= 1) cout << "0\n";
			else cout << max(0ll , n + 1 - 2 * lo) << "\n"; 
			continue;
		}
		for(int i = 0 ; i <= n ; i++) vec[i].clear();
		for(int i = 1 ; i <= n ; i++){
			for(int j = i + 1 ; j <= n ; j++){
				if(x[j] - x[i] <= d) vec[i].push_back(j); 
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 0 ; j <= n ; j++) num[j] = vis[j] = 0 , dis[j] = 1e9;
			dis[i] = 0 , num[i] = 1;
			pq.push({0 , i});
			while(!pq.empty()){
				auto p = pq.top(); pq.pop();
				if(vis[p.second]) continue;
				//cout << p.second << " " << num[p.second] << "\n";
				vis[p.second] = 1;
				for(auto j : vec[p.second]){
					if(dis[p.second] + 1 < dis[j]){
					//	cout << p.second << " " << j << "11\n";
						dis[j] = dis[p.second] + 1;
						num[j] = num[p.second];
						pq.push({dis[j] , j});
					}
					else if(dis[p.second] + 1 == dis[j] && num[p.second] < 5){
					//	cout << p.second << " " << j << "22\n";
						dis[j] = dis[p.second] + 1;
						num[j] += num[p.second];
						pq.push({dis[j] , j});
					}
				}
			}
			for(int j = 1 ; j <= n ; j++){
				if(num[j] == 2) ans++;
			//	cout << num[j] << " ";
			}
		//	cout << "\n"; 
		}
		cout << ans << "\n";
	}
	return 0;
}
