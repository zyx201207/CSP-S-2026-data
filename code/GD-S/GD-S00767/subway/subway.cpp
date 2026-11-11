#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<vector<int>> t(n+1),a(n+1);
	vector<vector<pair<int,int>>> tr(m+1);
	vector<vector<int>> dist(n+m+1,vector<int>(n+m+1,INT_MAX/2));
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		
		int k; cin >> k;
		for(int j=1;j<=k;j++){
			
			int x,y; 
			cin >> x >> y;
			tr[x].push_back({i,y});	
		} 
	}
	
	for(int i=1;i<=n;i++) dist[i][i] = 0;
	
	for(int k=1;k<=m;k++){
		int sz = tr[k].size();
		for(int i=0;i<sz;i++){
			
			for(int j=0;j<i;j++){
				
				int u = tr[k][i].first,v = tr[k][j].first;
				int x = tr[k][i].second,y = tr[k][j].second;
				dist[v][u] = dist[u][v] = min(dist[u][v],x+y);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	
	while(q--){
		int l,r;
		cin >> l >> r;
		if(l == r){
			cout << 0 << '\n';
			continue;
		}
		int szl = tr[l].size(),szr = tr[r].size();
		int ans = INT_MAX/2;
		for(int i=0;i<szl;i++){
			for(int j=0;j<szr;j++){
				ans = min(ans,dist[tr[l][i].first][tr[r][j].first]+tr[l][i].second+tr[r][j].second);
			}
		}
		cout << ans + w[l] + w[r] << '\n';
	}
	
		
	return 0;
}
