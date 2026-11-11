#include<bits/stdc++.h>
using namespace std;
long long _,n,m,d,Q;
long long w[500005];
long long a[505][25];
long long t[505][25];
long long k[505];
long long ans[1005][1005];
bool b[1005];
priority_queue<pair<long long,long long> > q; 
long long dp[405][405];
vector<pair<long long,long long> > e[1005]; 
int main(){
	freopen("subway.in","r",stdin);
//	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	if (1<=_&&_<=6){
		for(long long u=1;u<=m;u++){
			for(long long v=1;v<=m;v++){
				dp[u][v]=9999999999999999;
			}
		} 
		for(long long i=1;i<=n;i++){
			for(long long u=1;u<=k[i];u++){
				for(long long v=1;v<=k[i];v++){
					dp[a[i][u]][a[i][v]]=min(dp[a[i][u]][a[i][v]],t[i][u]+t[i][v]);
				}
			} 
		}
//		for(long long u=1;u<=m;u++){
//			for(long long v=1;v<=m;v++){
//				cout<<dp[u][v]<<' ';
//			}cout<<endl;
//		} cout<<endl;
		for(long long i=1;i<=m;i++){
			for(long long u=1;u<=m;u++){
				for(long long v=1;v<=m;v++){
					dp[u][v]=min(dp[u][v],dp[u][i]+dp[i][v]);
				}
			} 
		}
		long long x,y;
		while(Q--){
			cin>>x>>y;
			cout<<dp[x][y]+w[x]+w[y]<<endl;
		}
	}else if (7<=_&&_<=11){
		for(long long i=1;i<=n;i++){
			for(long long u=1;u<=k[i];u++){
				for(long long v=1;v<=k[i];v++){
					e[a[i][u]].push_back({a[i][v],t[i][u]+t[i][v]});
				}
			} 
		}
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=m;j++){
				ans[i][j]=9999999999999999;
			}
		} 
		long long uu,vv,ww;
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=m;j++) b[j]=false;
			q.push({0,i});ans[i][i]=0;
			while(!q.empty()){
				uu=q.top().second;q.pop();
				if (b[uu]==true) continue;
				b[uu]=true;
//				cout<<uu<<endl;
//				for(int l=1;l<=m;l++) cout<<b[l]<<' ';cout<<endl;
				for(long long j=0;j<e[uu].size();j++){
					vv=e[uu][j].first;ww=e[uu][j].second;
					if (ans[i][vv]>ans[i][uu]+ww){
						ans[i][vv]=ans[i][uu]+ww;q.push({-ans[i][vv],vv});
					}
				}
			}
		}
//		for(long long i=1;i<=m;i++){
//			for(long long j=0;j<e[i].size();j++){
//				cout<<i<<' '<<e[i][j].first<<' '<<e[i][j].second<<endl;
//			}cout<<endl;
//		}cout<<endl;
//		for(long long i=1;i<=m;i++){
//			for(long long j=1;j<=m;j++){
//				cout<<ans[i][j]<<' ';
//			}cout<<endl;
//		}cout<<endl;
		long long x,y;
		while(Q--){
			cin>>x>>y;
			cout<<ans[x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
}
