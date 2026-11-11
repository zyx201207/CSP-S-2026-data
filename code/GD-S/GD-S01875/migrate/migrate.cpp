#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
using ll = long long;
const int MAXN = 5005;

int c, t;
int n;
ll d;
ll pos[MAXN];
vector<int> G[MAXN];
ll dis[MAXN];
ll cnt[MAXN];
ll ans = 0;

int main(){
	freopen("migrate3.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> c >> t;
	while(t--){
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			G[i].clear();
		for(int i = 1; i <= n; i++)
			cin >> pos[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n && pos[j] - pos[i] <= d; j++)
				G[i].push_back(j);
		}
		for(int i = 1; i <= n; i++){
			memset(dis, 0x3f3f3f3f, sizeof(dis));
			memset(cnt, 0, sizeof(cnt));
			dis[i] = 0;
			cnt[i] = 1;
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
			q.push(mp(0, i));
			while(!q.empty()){
				int x = q.top().second;
				if(dis[x] < q.top().first){
					q.pop();
					continue;
				}
				q.pop();
				for(auto v : G[x]){
					if(dis[x] + 1 < dis[v])
						dis[v] = dis[x] + 1, q.push(mp(dis[v], v)), cnt[v] = cnt[x];
					else if(dis[x] + 1 == dis[v])
						cnt[v] += cnt[x];
				}
			}
			for(int j = 1; j <= n; j++)
				if(cnt[j] == 2) ans++;
		}
		cout << ans << "\n";
	}
} 
/*
0 1
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000

*/
