#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int M=5e5+5;

int c,n,m,d,q;
vector<pair<int,int> > sub[M];
ll w[M];
ll t[501][50001];

ll e[505][505];

int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(e,0x3f,sizeof(e));

	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++) e[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			scanf("%d%lld",&a,&t[i][j]);
			
			for(int x=0;x<sub[a].size();x++){
				int j1=sub[a][x].first,u=sub[a][x].second;
				
				e[u][i]=min(e[u][i],t[u][j1]+t[i][j]);
				e[i][u]=e[u][i];
			}
			sub[a].push_back({j,i});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	
	while(q--){
		int s,ed;
		scanf("%d%d",&s,&ed);
		ll ans=1e16;
		for(int x=0;x<sub[s].size();x++){
			int j=sub[s][x].first;int u=sub[s][x].second;
			
			for(int y=0;y<sub[ed].size();y++){
				int k=sub[ed][y].first;int v=sub[ed][y].second;
				
				ans=min(ans,1LL*(e[u][v]+t[u][j]+t[v][k]));
			}
		}
		printf("%lld\n",ans);
	}

}
