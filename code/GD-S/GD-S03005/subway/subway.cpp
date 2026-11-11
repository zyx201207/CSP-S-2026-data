#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5;
int c,n,m,d,q;
int W[maxm];
struct node{
	int v,w;
	node(){}
	node(int vv,int ww){
		v=vv,w=ww;
	}
};
vector<node>G[maxm+maxn];
struct qu{
	int u,d;
	qu(){}
	qu(int uu,int dd){
		u=uu,d=dd;
	}
	bool operator<(const qu &r)const{
		return d>r.d;
	}
};
bool vis[maxm+maxn];
int bfs(int s,int t){
	vis[s]=true;
	priority_queue<qu>q;
	q.push(qu(s,0));
	while(!q.empty()){
		qu now=q.top();
//		cout<<now.u<<" "<<now.d<<"\n";
		q.pop();
		for(int i=0;i<G[now.u].size();i++){
			int v=G[now.u][i].v,w=G[now.u][i].w;
			if(!vis[v]){
				if(v==t)return now.d+w;
				q.push(qu(v,now.d+w));
				vis[v]=true;
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,w;
			cin>>u>>w;
			G[m+i].push_back(node(u,w));
			G[u].push_back(node(m+i,w));
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		memset(vis,0,sizeof(vis));
		int ans=bfs(s,t);
		cout<<ans+W[s]+W[t]<<"\n";
	}
	return 0;
}
