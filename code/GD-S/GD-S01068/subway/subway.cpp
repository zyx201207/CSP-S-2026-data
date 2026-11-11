#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int w[5000003];
struct Node{
	int v,w;
};
struct Edge{
	int u,v,w;
	bool operator > (const Edge &o) const{
		return w<o.w;
	}	
};
vector<Node>vt[100003];
int k[10003];
bool vis[100003];
int ans[100003];
bool vi[10000003];
int f(int start,int tar){
//	cout<<1;
	ans[start]=0;
	priority_queue<Edge,vector<Edge>,greater<Edge> >que;
	for(Node o:vt[start]){
		int v=o.v;
		int w=o.w;
		que.push({start,v,w});
	}
	while(1){
//		cout<<1;
		Edge lin=que.top();
		que.pop();
		int u=lin.u;
		int v=lin.v;
		int w=lin.w;
//		cout<<u<<' '<<v<<' '<<w<<'\n';
		if(vis[v]) continue;
		if(v==tar) return ans[u]+w;
		ans[v]=ans[u]+w;
		vis[v]=true;
		for(Node o:vt[v]){
			que.push({v,o.v,o.w});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int pre=-1;
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			if(vi[x]){
				vt[x+3*m].push_back({m+x,y});
				vt[m+x].push_back({x+3*m,y});
			}else{
				vt[x].push_back({m+x,y});
				vt[m+x].push_back({x,y});
			}
			vi[x]=true;
			if(pre!=-1){
				vt[x].push_back({pre,0});
				vt[pre].push_back({x,0});
				vt[x+3*m].push_back({pre,0});
				vt[pre].push_back({x+3*m,0});
				vt[x].push_back({pre+3*m,0});
				vt[pre+3*m].push_back({x,0});
				vt[x+3*m].push_back({pre+3*m,0});
				vt[pre+3*m].push_back({x+3*m,0});				
			}
			pre=x;
		}
	}
	for(int i=1;i<=m;i++){
		vt[i+m].push_back({i+2*m,w[i]});
		vt[i+2*m].push_back({i+m,w[i]});
	}
	while(q--){
//		cout<<1;
		int x,y;
		cin>>x>>y;
		cout<<f(x+2*m,y+2*m)<<'\n';
		for(int i=1;i<=m*3;i++) vis[i]=false;
	}
	return 0;
} 
