#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2+5,M=5e5+5;
struct edge{int v,w;};
struct node{
	int u,w;
	bool operator<(const node &x)const{
		return w<x.w;
	}
	bool operator>(const node &x)const{
		return w>x.w;
	}
};
int c,n,m,d,q;
int w[M];
int D[N][N];
vector<edge>e[M];
bool vis[M];
int d2[M];
priority_queue<node,vector<node>,greater<node>>qe;
void dij(int s){
	int cnt=0;
	memset(vis,0,sizeof vis);
	memset(d2,0x3f,sizeof d2); 
	qe.push({s,0});
	d2[s]=0;
	while(qe.size()){
		auto[u,w]=qe.top();
		qe.pop();
		if(u>m)D[s-m][u-m]=min(d2[u],D[s-m][u-m]);
		if(vis[u])continue;
		vis[u]=1;
		for(auto[v,vw]:e[u]){       
			if(d2[u]+vw<d2[v]){
				d2[v]=d2[u]+vw;
				qe.push({v,w+vw});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	memset(D,0x3f,sizeof D);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			e[i+m].push_back({x,t});
			e[x].push_back({i+m,t});
		}
	}
	for(int i=1;i<=n;i++)dij(i+m);
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<"0\n";
			continue;
		}
		int minn=1e18;
		for(auto[v,vw]:e[x]){
			for(auto[v2,vw2]:e[y]){
				minn=min(minn,D[v-m][v2-m]+vw+vw2);
			}
		}
		cout<<minn+w[x]+w[y]<<"\n";
	}
	return 0;
} 
/*

*/
