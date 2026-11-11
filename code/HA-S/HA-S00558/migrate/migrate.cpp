#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int c, t;
int n;
long long d;
long long x[N];
vector<int>g[N];
long long cnt[N];
bool vis[N];
long long dis[N];
long long ans;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
			g[i].clear();
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
//				cout<<llabs(x[i] - x[j])<<' '<<i<<' '<<j<<endl;
				if(llabs(x[i] - x[j]) <= d){
//					cout<<"A:"<<x[i]<<' '<<x[j]<<endl;
//					cout<<i<<' '<<j<<endl;
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			priority_queue<pair<long long, int> >q;
			for(int j = 1;j <= n;j++){
				dis[j] = INT_MAX;
				vis[j] = 0;
				cnt[j] = 1;
			}
			q.push({0, i});
			dis[i] = 0;
			while(!q.empty()){
				pair<int, int>now = q.top();q.pop();
				int u = now.second;
				if(vis[u]) continue ;
				vis[u] = 1;
				for(auto v : g[u]){
//					cout<<"A:"<<u<<' '<<"B:"<<v<<endl;
					if(dis[v] > dis[u] + 1){
						dis[v] = dis[u] + 1;
						cnt[v] = cnt[u];
						q.push({-dis[v], v});
					}
					else if(dis[v] == dis[u] +1){
						q.push({-dis[v], v});
						cnt[v]++;
					}
				}
			}
			for(int j = 1;j <= n;j++){
//				if(j == i) continue ;
//				cout<<dis[j]<<' ';
//				cout<<cnt[j]<<' ';
				if(cnt[j] == 2){
//					cout<<"Ans:"<<i<<' '<<j<<endl;
					ans++;
				}
			}
//			cout<<endl;
		}
//		cout<<ans<<endl;
		ans /= 2;
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

*/

