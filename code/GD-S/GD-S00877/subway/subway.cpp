#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
vector<pair<long long,long long>> g[1000];
long long Wm[1000];//第i个地铁站的地铁口走到站厅需要的时间
long long xiant[100][1000]; //第i条线的第j个站点所需时间； 
long long zhongx[100];//第i个线路的总站点数 
long long jihua[100][4];//计划i的起点与终点 
long long x[100][1000];
long long dist[1000],visit[1000];

long long djstra(long long start,long long end){
//	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
	memset(dist,0x3f,sizeof(dist));
	memset(visit,0,sizeof(visit));
	dist[1]=0;
	for(long long i=1;i<=m;i++){
		long long sb=0x3f3f3f3f3f3f3f3f;
		long long z=0;
		for(long long j=1;j<=m;j++){
			if(sb>dist[j]&&!visit[j]){
				sb=dist[j];
				z=j;
			}
		}
		visit[z]=1;
		for(auto e:g[z]){
			if(e.first<dist[e.second]){
				dist[e.second]=e.first;
			}
		}
	}
	return dist[end];
//	pq.push_back(dist[1],start);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>Wm[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>zhongx[i];
		for(long long j=1;j<=zhongx[i];j++){

			cin>>x[i][j];
			cin>>xiant[i][x[i][j]];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>jihua[i][1]>>jihua[i][2];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=2;j<=zhongx[i];j++){
			long long w1=xiant[i][x[i][j-1]];
			long long w2=xiant[i][x[i][j]];//xia yi ge zhandian;
			g[x[i][j-1]].push_back({w1+w2,x[i][j]});
			
		}
	}
	for(long long i=1;i<=q;i++){
		cout<<Wm[jihua[i][1]]+Wm[jihua[i][2]]+djstra(jihua[i][1],jihua[i][2])<<"\n";
	}
	
	
	return 0;
}


