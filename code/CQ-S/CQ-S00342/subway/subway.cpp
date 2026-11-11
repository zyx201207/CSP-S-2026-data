#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 lll;
typedef long double ld;
mt19937 rnd(time(0));
const int N=520,M=5e5+114;
vector<pair<int,ll>> g1[M],g2[M];
ll w[M],dp[N][N];
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	} 
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a;
			ll t;
			cin>>a>>t;
			g1[a].push_back({i,t});
			g2[i].push_back({a,t});
		}
	}
	for(int i=1;i<=m;++i){
		sort(g1[i].begin(),g1[i].end());
	}
	for(int i=1;i<=n;++i){
		sort(g2[i].begin(),g2[i].end());
	}
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i)dp[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			int k=0;
			if(g2[j].empty()) continue; 
			for(auto &t:g2[i]){
				int u=t.first;
				ll w=t.second;
				while(k!=(ll)g2[j].size()-1&&g2[j][k].first<u){
					k++;
				}
				if(g2[j][k].first==u){
					dp[i][j]=min(dp[i][j],w+g2[j][k].second);
					dp[j][i]=min(dp[j][i],w+g2[j][k].second);
				}
			}
		}
	}
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
			}
		}
	}
//	cerr<<"ERR:\n";
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cerr<<dp[i][j]<<" ";
//		}
//		cerr<<"\n";
//	}
//	cerr<<"ERR\n";
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		ll res=LLONG_MAX;
		for(auto &u:g1[x]){
			for(auto &v:g1[y]){
				res=min(res,dp[u.first][v.first]+u.second+v.second);
			}
		}
		cout<<res+w[x]+w[y]<<"\n";
	}
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
