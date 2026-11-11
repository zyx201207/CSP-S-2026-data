#include<bits/stdc++.h>
using namespace std;

int n,m,q,a[500010];
long long dist[510][510];

struct edge{
	int v,w;
};

vector<edge> e[500510];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	int c,p;
	cin>>c>>n>>m>>p>>q;
	for(int i = 1;i <= m;i++) cin>>a[i];
	for(int i = 1,k;i <= n;i++){
		dist[i][i]=0;
		cin>>k;
		for(int j = 1,v,w;j <= k;j++) cin>>v>>w,e[i+m].push_back({v,w}),e[v].push_back({i+m,w});
	}
	for(int i = 1;i <= m;i++){
		for(auto ed1:e[i]){
			int v1=ed1.v,w1=ed1.w;
			for(auto ed2:e[i]){
				int v2=ed2.v,w2=ed2.w;
				if(v1==v2) continue;
				dist[v1-m][v2-m]=dist[v2-m][v1-m]=min(dist[v1-m][v2-m],1ll*w1+w2);
			}
		}
	}
	for(int k = 1;k <= n;k++) for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--){
		int x,y;
		long long minn=1e18;
		cin>>x>>y;
		for(auto edx:e[x]){
			int vx=edx.v,wx=edx.w;
			for(auto edy:e[y]){
				int vy=edy.v,wy=edy.w;
				minn=min(minn,dist[vx-m][vy-m]+wx+wy);
			}
		}
		minn+=1ll*a[x]+a[y];
		cout<<minn<<'\n';
	}
	return 0;
}
