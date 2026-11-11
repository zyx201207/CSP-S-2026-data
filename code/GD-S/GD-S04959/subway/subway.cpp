#include <bits/stdc++.h>
using namespace std;
const long long inf = (1ll<<62);

int c,n,m,d,q;
long long ex[500009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> ex[i];
	vector<pair<int,long long>> stn[m+1];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int a;
			long long t;
			cin >> a >> t;
			stn[a].push_back({i,t});
		}
	}
	vector<vector<long long>> ve(n+1,vector<long long>(n+1,inf));
	vector<pair<int,long long>> tu[n+2];
	for(int i=1;i<=m;i++){
		for(int j=0;j<stn[i].size()-1;j++){
			for(int jj=j+1;jj<stn[i].size();jj++){
				int u=stn[i][j].first,v=stn[i][jj].first;
				long long w=stn[i][j].second+stn[i][jj].second;
				ve[u][v] = min(ve[u][v],w);
				ve[v][u] = ve[u][v];
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ve[i][j] != inf){
				tu[i].push_back({j,ve[i][j]});
				tu[j].push_back({i,ve[i][j]});
			}
		}
	}
	
	while(q--){
		int x,y;
		cin >> x >> y;
		tu[0].clear();
		tu[n+1].clear();
		for(int i=0;i<stn[x].size();i++) tu[0].push_back(stn[x][i]);
		for(int i=0;i<stn[y].size();i++) tu[stn[y][i].first].push_back({n+1,stn[y][i].second});
		//for(int i=0;i<stn[y].size();i++) cout << stn[y][i].first;cout << y;
		long long ans=0;
		vector<long long> d(n+2,inf);
		using p = pair<long long,int>;
		priority_queue<p,vector<p>,greater<p>> pq;
		pq.push({0,0});//for(int i=0;i<stn[x].size();i++) pq.push({stn[x][i].second,stn[x][i].first});
		while(!pq.empty()){
			auto [dv,v] = pq.top();
			pq.pop();
			if(d[v] != inf) continue;
			d[v] = dv;//cout << dv << ' ' << v;
			if(v == n+1) break;
			for(int i=0;i<tu[v].size();i++){
				auto [to,w] = tu[v][i];//cout << ' ' << w << to;
				pq.push({d[v]+w,to});
			}//cout << endl; 
		}
		cout << ex[x] + d[n+1] + ex[y] << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
