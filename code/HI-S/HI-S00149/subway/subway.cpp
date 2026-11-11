#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 5e5 + 5;
const int N = 505;

int w[M];

struct stu{
	int i; // dian
	ll t; // shijian
};
vector<stu> poin[N];
vector<stu> xian[M];

ll dist[N][N];

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		
		for(int j = 1; j <= k; j++){
			int a,t;
			cin >> a >> t;
			
			poin[i].push_back({a,t});
			xian[a].push_back({i,t});
		}
	}
	
	memset(dist,0x3f,sizeof dist);
	
	for(int i = 1; i <= m; i++){
		for(int fa = 0; fa < xian[i].size(); fa++){
			for(int fb = fa+1; fb < xian[i].size(); fb++){
				stu nowa = xian[i][fa];
				stu nowb = xian[i][fb];
				
				dist[nowa.i][nowb.i] = min(dist[nowa.i][nowb.i] , nowa.t+nowb.t);
				dist[nowb.i][nowa.i] = min(dist[nowb.i][nowa.i] , nowa.t+nowb.t);
			}
		}
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				
				if(i == j){
					dist[i][j] = 0;
					continue;
				}
				
				if(dist[i][k] < 1e17 && dist[k][j] < 1e17)
					dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
			}
		}
	}
	
	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(dist[i][j] < 1e10){
				cout << dist[i][j] << ' ';
			}
		}
		cout << endl;
	}*/
	
	while(q--){
		int x,y;
		cin >> x >> y;
		
		ll ans = 1e18;
		for(int i = 0; i < xian[x].size(); i++){
			for(int j = 0; j < xian[y].size(); j++){
				stu nowa = xian[x][i];
				stu nowb = xian[y][j];
				
				if(dist[nowa.i][nowb.i] > 1e17) continue;
				
				ll all = nowa.t+nowb.t+dist[nowa.i][nowb.i];
				ans = min(ans , all);
			}
		}
		//cout << ans << '\n';
		cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}
