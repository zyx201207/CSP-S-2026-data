#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int N=502,M=5e5+9;
ll D[N][N];
ll w[M];
vector<pii> tra[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u;ll t;
			cin>>u>>t;
			tra[u].push_back({i,t});
		}
	}
//	cout<<1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)D[i][j]=1e18;
		D[i][i]=0;
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<tra[i].size();j++){
			int u=tra[i][j].first;
			ll w1=tra[i][j].second;
			for(int k=0;k<j;k++){
				int v=tra[i][k].first;
				ll w2=tra[i][k].second;
				D[u][v]=D[v][u]=min(D[u][v],w1+w2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			for(int k=1;k<=n;k++){
				D[i][j]=D[j][i]=min(D[i][j],D[i][k]+D[k][j]);
			}
//			printf("%lld ",D[i][j]);
		}
//		printf("\n");
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		ll ans=1e18;
		for(int i=0;i<tra[s].size();i++){
			int u=tra[s][i].first;
			ll w1=tra[s][i].second;
			for(int j=0;j<tra[t].size();j++){
				int v=tra[t][j].first;
				ll w2=tra[t][j].second;
//				if(u==v)
				ans=min(ans,D[u][v]+w1+w2);
			}
		}
		cout<<w[s]+w[t]+ans<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/