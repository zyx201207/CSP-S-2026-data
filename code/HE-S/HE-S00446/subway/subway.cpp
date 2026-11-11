#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,d,c,dp[530][530],q,w[N],k[530],u,v;
vector<pair<long long,long long> > p[N];
vector<pair<long long,long long> > tme[530];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=n+10;i++){
		for(int j=0;j<=n+10;j++){
			dp[i][j]=1e18;
		}
	} 
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long hh,t;
			cin>>hh;
			cin>>t;
			p[hh].push_back({i,t});
			tme[i].push_back({hh,t});
		}
	}for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int x=0;x<p[i].size();x++){
				if(j==x)continue;
				long long jf=p[i][j].first,js=p[i][j].second;
				long long xf=p[i][x].first,xs=p[i][x].second;
				int ll=min(dp[jf][xf],xs+js);
				dp[jf][xf]=dp[xf][jf]=ll;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dp[i][j]=0;
				continue;
			}
			for(int x=1;x<=n;x++){
				dp[j][i]=dp[i][j]=min(dp[i][x]+dp[j][x],dp[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=1e18;
		cin>>u>>v;
		for(int j=0;j<p[u].size();j++){
			for(int x=0;x<p[v].size();x++){
				long long jf=p[u][j].first,js=p[u][j].second;
				long long xf=p[v][x].first,xs=p[v][x].second;
				ans=min(ans,dp[jf][xf]+js+xs);
			}
		}cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
} 
