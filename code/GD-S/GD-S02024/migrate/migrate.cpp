#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int kmaxN = 310;
const ll inf = 1e12;
int T,c;
ll n,d,x[kmaxN];
vector<ll> g[kmaxN];
ll dis[kmaxN][kmaxN];
int isp[kmaxN][kmaxN];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ll ans = 0;
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++){
				dis[i][j] = inf;
				isp[i][j] = 0;
			} 
//		for(int i = 1;i <= n;i++) g[i].erase();
		for(int i = 1;i <= n;i++) cin>>x[i];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < i;j++){
				if(x[i] - x[j] <= d){
				//	g[i].push_back(j);
				//	g[j].push_back(i);
					dis[i][j] = dis[j][i] = 1;
				}
			}
			for(int j = i+1;j <= n;j++){
				if(x[j] - x[i] <= d){
				//	g[j].push_back(i);
				//	g[i].push_back(j);
					dis[i][j] = dis[j][i] = 1;
				}
			}
		}
		for(int k = 1;k <= n;k++){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= n;j++){
					if(dis[i][k] + dis[k][j] < dis[i][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
						if(isp[i][j] && i != j){
							if(isp[i][j] == 1) ans--;
							isp[i][j] = isp[j][i] = 0;
						}
					}else if(dis[i][k] + dis[k][j] == dis[i][j]){
						if(!isp[i][j]&& i != j){
							isp[i][j] = isp[j][i] = 1;
							ans++;
						}else if(isp[i][j] == 1&& i != j){
							isp[i][j] = isp[j][i] = 2;
							ans--;
						}
					}
				}
			} 
		}
//		for(int i = 1;i <= n;i++){
//			for(int j = 1;j <= n;j++) cout<<dis[i][j]<<' ';
//			cout<<'\n';
//		}
//for(int i = 1;i <= n;i++) for(int j  = i+1;j <= n;j++) if(isp[i][j]) cout<<i<<j;
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
