#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,d,c;
const int N = 1e5+9,INF = 1e18;
int x[N];
int dis[N],tim[N];
int check(int u){
	fill(dis+1,dis+n+1,INF);
	fill(tim+1,tim+n+1,0);
	dis[u] = 0;
	tim[u] = 1;
	for(int i = u;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(x[j] - x[i] > d) break;
			if(dis[j] > dis[i] + 1){
				dis[j] = dis[i] + 1;
				tim[j] = tim[i];
			}else if(dis[j] == dis[i] + 1){
				tim[j] += tim[i];
			}
		}
	}
	int ans = 0;
	for(int i = u;i <= n;i++){
		if(tim[i] == 2) ans++;
	}
	return ans;
}
void solve(){
	cin>>n>>d;
	if(c <= 10){
		for(int i = 1;i <= n;i++) cin>>x[i];
		int ans = 0;
		for(int i = 1;i <= n;i++){
			ans += check(i);
		}
		cout<<ans<<"\n";
		return ;
	}else{
		for(int i = 1;i <= n;i++) cin>>x[i];
		int tp = x[2] - x[1];
		cout<<n - tp / d<<"\n";
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int t;cin>>c>>t;
	while(t--) solve();
	return 0;
}
