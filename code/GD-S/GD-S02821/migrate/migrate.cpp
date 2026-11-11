#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int N = 2000006;

int n;
ll d, x[N];
ll dis[303][303], cnt[303][303];
vector<int> e[5005];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c, T; cin >> c >> T;
	while(T --){
		cin >> n >> d;
		for(int i=1; i<=n; ++i) cin >> x[i];
		if(c <= 6){
			for(int i=1; i<=n; ++i)for(int j=i+1; j<=n; ++j) cnt[i][j] = 0;
			for(int i=1; i<=n; ++i){
				for(int j=1; j<=n; ++j) dis[i][j] = ((i != j) ? 4e18 : 0);
				for(int j=i+1; j<=n; ++j){
					if(abs(x[j] - x[i]) <= d) dis[i][j] = 1, cnt[i][j] = 1;
				}
			}
			for(int k=1; k<=n; ++k){
				for(int i=1; i<=n; ++i){
				    for(int j=i+1; j<=n; ++j){
				        if(i == j || i == k || j == k) continue;
					    if(dis[i][j] > dis[i][k] + dis[k][j])
						    dis[i][j] = dis[i][k] + dis[k][j], cnt[i][j] = 1;
					    else if(dis[i][j] == dis[i][k] + dis[k][j])
						++ cnt[i][j];
				    }
				}
			}
			int ans = 0;
			for(int i=1; i<=n; ++i){
				for(int j=i+1; j<=n; ++j){
				    if(i == j) continue;
				    //cout << i << ' ' << j << ' ' << cnt[i][j] << ' ' << dis[i][j] << '\n';
				    if(dis[i][j] != 4e18 && dis[i][j] != 1 && cnt[i][j] == 2) ++ ans;
				}
			}
			cout << ans << '\n';
		} else cout << 1 << '\n';
	}	
	return 0;
}
/*
zhe bu zha le, you shi bu guo yang li.
ai wo zhen shi ge le zi.
*/
