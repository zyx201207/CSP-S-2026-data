#include<bits/stdc++.h>
using namespace std;
int Case_Num;
int n,m,d,q,x,y;
long long w[500005],dist[505][505];
pair<int,long long>G[500005][22];
int Len[500005]={0};
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>Case_Num>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		int K,Station;
		long long Time_Cost;
		cin>>K;
		for(int j=1;j<=K;++j)
			cin>>Station>>Time_Cost,G[Station][++Len[Station]]={i,Time_Cost};
	}
//	#Calculate
	memset(dist,15,sizeof dist);
	for(int i=1;i<=500;++i)
		dist[i][i]=0LL;
	for(int k=1;k<=m;++k)
		for(int i=1;i<=Len[k];++i)
			for(int j=1;j<=Len[k];++j)
				dist[G[k][i].first][G[k][j].first]=min(dist[G[k][i].first][G[k][j].first],G[k][i].second+G[k][j].second);
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
//	#Answer
	while(q--){
		cin>>x>>y;
		long long Min=1e18;
		for(int i=1;i<=Len[x];++i)
			for(int j=1;j<=Len[y];++j)
				Min=min(Min,dist[G[x][i].first][G[y][j].first]+G[x][i].second+G[y][j].second);
		cout<<(Min+w[x]+w[y])<<'\n';
	}
	return 0;
}
