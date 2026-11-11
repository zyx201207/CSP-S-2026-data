#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int C,n,m,d,Q,dis[N],w[N];
priority_queue<pair<int,int>>q;
vector<pair<int,int>>v[N];
bool vis[N];
void dij(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		int pt=q.top().second;
		q.pop();
		if(vis[pt])continue;
		vis[pt]=1;
		for(auto t:v[pt]){
			int ww=t.second,yy=t.first;
			if(dis[pt]+yy<dis[ww]){
				dis[ww]=dis[pt]+yy;
				q.push({-dis[ww],ww});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1,W;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,K;i<=n;i++){
		cin>>K;
		for(int j=1,A,T;j<=K;j++){
			scanf("%d%d",&A,&T);
			v[A].push_back({T,i+m});
			v[i+m].push_back({T,A});
		}
	}
	for(int i=1;i<=Q;i++){
		int U,V;
		scanf("%d%d",&U,&V);
		dij(U);
		printf("%d\n",(dis[V]+w[U]+w[V]));
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
