#include<bits/stdc++.h>
#define int long long
using namespace std;
int cs,t,n,d,vis[5145];
pair<int,int> dist[5100][5100];
vector<int> g[5145];
void dfs(int now,int from,int s,int t,int sum){
	if(now==t){
		if(dist[s][t].first==0){
			dist[s][t].first=sum;
			dist[s][t].second=1;
		}
		else if(sum<dist[s][t].first){
			dist[s][t].first=sum;
			dist[s][t].second=1;
		}
		else if(sum==dist[s][t].first){
			dist[s][t].second++;
		}
	}
	for(int i:g[now]){
		if(i!=from&&!vis[i]){
			vis[i]=1;
			dfs(i,now,s,t,sum+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cs>>t;
	while(t--){
		if(cs<11){
			cin>>n>>d;
			vector<int> x;
			x.resize(n+1);
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j) continue;
					if(abs(x[i]-x[j])<=d){
						g[i].push_back(j);
						g[j].push_back(i);
//						cout<<i<<' '<<j<<'\n';
					}
					else break;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(i==j) continue;
					dfs(i,-1,i,j,0);
				}
			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					cout<<dist[i][j].first<<' ';
//				}
//				cout<<'\n';
//			}
//			for(int i=1;i<=n;i++){
//				for(int j=1;j<=n;j++){
//					cout<<dist[i][j].second<<' ';
//				}
//				cout<<'\n';
//			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dist[i][j].second==2){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=1;i<=n;i++) g[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dist[i][j]={0,0};
			}
		}
		else{
			cout<<0<<'\n';
		}
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
