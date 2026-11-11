#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e16;
int T,n,m,dbw,d,q,w[800005],dis[605][605];
vector<pair<int,int>> e[800005];
void solve(){
	cin>>dbw>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) dis[i][j]=inf;
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,c,val;j<=k;j++){
			cin>>c>>val;
			e[c].push_back({i,val});
		}
	}
	for(int p=1,k;p<=m;p++){
		k=e[p].size();
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				dis[e[p][i].first][e[p][j].first]
				=dis[e[p][j].first][e[p][i].first]
				=min(dis[e[p][i].first][e[p][j].first],
				e[p][i].second+e[p][j].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 
	for(int i=1;i<=n;i++) dis[i][i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//		}
//	}
	while(q--){
		int u,v,ans;
		cin>>u>>v;
		ans=inf;
		for(int i=0;i<e[u].size();i++){
			for(int j=0;j<e[v].size();j++){
				ans=min(ans,
				w[u]+w[v]+e[u][i].second+e[v][j].second
				+dis[e[u][i].first][e[v][j].first]);
//				cout<<u<<" "<<e[u][i].first<<"  "<<v<<" "<<e[v][j].first<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	T=1;
	while(T--) solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
