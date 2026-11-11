#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500;
const int K=1e4+10;
const int MAX_MAX=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[K],k;
int vis[K],dis[K][K];
vector<pair<int,int>> tu[K+N];
void zui(int cu){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	for(int i=1;i<=m;i++){
		vis[i]=0,dis[cu][i]=MAX_MAX;
	}
	q.push({0,cu});
	while(!q.empty()){
		int x=q.top().first,y=q.top().second;
		q.pop();
		if(vis[y]) continue;
		vis[y]=1;
		for(int i=0;i<tu[y].size();i++){
			int zhon=tu[y][i].first,cw=tu[y][i].second;
			for(int j=0;j<tu[zhon].size();j++){
				int to=tu[zhon][j].first,ch=tu[zhon][j].second;
				if(x+cw+ch<dis[cu][to]&&!vis[to]){
					dis[cu][to]=x+cw+ch;
					q.push({dis[cu][to],to});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%lld%lld",&a,&t);
			tu[i+m].push_back({a,t});
			tu[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=m;i++){
		zui(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}
