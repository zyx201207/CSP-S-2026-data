#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a,t,kk,dp[505][505],p[505][505],ans,u,v;
vector < pair<long long,long long> > st[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>a>>t;
			st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<st[i].size();j++){
			long long lj=st[i][j].first;
			for(int k=j+1;k<st[i].size();k++){
				long long lk=st[i][k].first;
				dp[lj][lk]=dp[lk][lj]=st[i][j].second+st[i][k].second;
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		cout<<dp[i][j]<<" ";
	//	}cout<<endl;
	//}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				
				if(dp[i][j]>dp[i][k]+dp[k][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	while(q--){
		ans=INT_MAX;
		cin>>u>>v;
		for(int i=0;i<st[u].size();i++){
			long long li=st[u][i].first;
			for(int j=0;j<st[v].size();j++){
				long long lj=st[v][j].first;
				if(st[u][i].second+st[v][j].second+dp[li][lj]<ans)cout<<li<<" "<<lj<<endl;
				ans=min(ans,st[u][i].second+st[v][j].second+dp[li][lj]);
			}	
		}
		cout<<ans+w[u]+w[v]<<endl;
	}
	
	return 0;
}

