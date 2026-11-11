#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int c,n,m,d,qq,w[N];
int op,a,t,qx,qy;
int dis[N];

struct edge{
	int to,ti;
	bool operator<(edge b)const{
		return ti>b.ti;
	}
};
vector<edge> g[N],hav[N];
priority_queue<edge> q;

int dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[qx]=0;
	while(!q.empty()) q.pop();
	q.push({qx,0});
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		if(now.to==qy) break;
		for(auto i:hav[now.to]){
			int tim=now.ti+i.ti;
			for(auto j:g[i.to]){
				if(j.to==now.to) continue;
				if(tim+j.ti<dis[j.to]){
					dis[j.to]=tim+j.ti;
					q.push({j.to,tim+j.ti}); 
				}
			}
		}
	}
	return dis[qy];
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>op;
		while(op--){
			cin>>a>>t;
			g[i].push_back({a,t});
			hav[a].push_back({i,t});
		}
	}
	while(qq--){
		cin>>qx>>qy;
		printf("%lld\n",dij()+w[qx]+w[qy]);
	}
	return 0;
}
