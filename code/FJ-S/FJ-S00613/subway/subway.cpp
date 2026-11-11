#include<bits/stdc++.h>
using namespace std;

const int MAXK=5e5+10,MAXD=20+10,MAXN=5e2+10,MAXS=MAXK*3;
int c,n,m,d,q;
int dis[MAXS],vis[MAXS];
struct node{
	int v,w;
	bool operator >(const node a)const{
		return w>a.w;
	}
};
vector<node> e[MAXS];
int w[MAXK];
int a[MAXK],t[MAXK];
priority_queue<node,vector<node>,greater<node> > qq;

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	qq.push({s,0});
	while(!qq.empty()){
//		cout<<qq.top().v<<' '<<qq.top().w<<endl;
		int u=qq.top().v;
		qq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v,w=e[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qq.push({v,dis[v]});
//				cout<<u<<' '<<v<<' '<<dis[v]<<endl;
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
		e[2*i].push_back({2*i+1,w[i]});
		e[2*i+1].push_back({2*i,w[i]});
	}
	
	int idx=0,idx2=2*m;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[idx]>>t[idx];
			a[idx]--;
			e[idx2].push_back({a[idx]*2+1,t[idx]});
			e[a[idx]*2+1].push_back({idx2,t[idx]});
			if(j!=0){
				e[idx2].push_back({idx2-1,0});
				e[idx2-1].push_back({idx2,0});
			}
			idx++,idx2++;
		}
	}
	
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		dij(2*x);
		cout<<dis[2*y]<<endl;
	}
	
	return 0;
}
