#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq,w[500001];
struct edges{
	int v;
	long long t;
	operator >(const edges &a)const{
		return t>a.t;
	}
};
vector<edges> g[500501];
int id(int x){
	return x+500000;
}
void solve(int s,int e){
	long long dis[500501];
	bool vis[500501];
	memset(dis,0x3f3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<edges,vector<edges>,greater<edges>> q;
	dis[s]=0; vis[s]=true;
	q.push(edges{s,0});
	while(!q.empty()){
		edges k=q.top();
		q.pop();
		for(int i=0;i<g[k.v].size();i++){
			int nv=g[k.v][i].v;
			long long nt=g[k.v][i].t+dis[k.v];
			if(nv==e){
				cout<<nt<<endl;
				return;
			}
			if(!vis[nv]){
				vis[nv]=true;
				dis[nv]=nt;
				q.push(edges{nv,nt});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int i=1;i<=k;i++){
			int v,t;
			cin>>v>>t;
			g[id(i)].push_back(edges{v,t});
			g[v].push_back(edges{id(i),t});
		}
	}
	for(int i=1;i<=qq;i++){
		int s,e;
		cin>>s>>e;
		solve(s,e);
	}
	return 0;
}
