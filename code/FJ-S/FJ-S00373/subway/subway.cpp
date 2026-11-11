#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long dis[505][505];
vector<pair<int,long long>>e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			dis[i][j]=dis[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int v;
		scanf("%d",&v);
		while(v--){
			int x;
			long long t;
			scanf("%d%lld",&x,&t);
			e[x].emplace_back(i,t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<e[i].size();j++){
			pair<int,long long>x=e[i][j];
			for(int k=0;k<j;k++){
				pair<int,long long>y=e[i][k];
				dis[x.first][y.first]=dis[y.first][x.first]=min(dis[x.first][y.first],x.second+y.second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			for(int k=1;k<=n;k++){
				if(i==k||j==k){
					continue;
				}
				dis[j][k]=dis[k][j]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=1e18;
		for(pair<int,long long>x:e[u]){
			for(pair<int,long long>y:e[v]){
				ans=min(ans,dis[x.first][y.first]+x.second+y.second);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
}
