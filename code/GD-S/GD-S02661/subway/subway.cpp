#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct s{
	int x,y,id;
};
struct ss{
	int sum,id;
}ans[100005];
bool cmp(s a,s b){
	if(a.x==b.y)return a.y<b.y;
	return a.x<b.x;
}
bool cmp1(ss a,ss b){
	return a.id<b.id;
}
priority_queue<pair<int,int> > qq;
struct node{
	int v,w;
};
bool vis[500005],uis[10005];
vector<node> g[500005];
int c,n,m,dx,q,k,a,t;
int d[500005],w[500005];
void dij(int u){
	memset(d,127,sizeof d);
	d[u]=0;
	memset(vis,false,sizeof vis);
	qq.push(make_pair(0,u));
	while(!qq.empty()){
		int u=qq.top().second;
		qq.pop();
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(vis[v])continue;
			if(d[u]+w<d[v]){
				d[v]=d[u]+w;
				
				qq.push(make_pair(-d[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>dx>>q;
	int tot=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			
			g[++tot].push_back((node){a,t});
			g[a].push_back((node){tot,t});
			if(j>1)g[tot].push_back((node){tot-1,0});
			if(j>1)g[tot-1].push_back((node){tot,0});
		}
	}
	s x[100005];
	for(int i=1;i<=q;i++){
		
		cin>>x[i].x>>x[i].y;
		x[i].id=i;
	}
	memset(uis,true,sizeof uis);
	sort(x+1,x+q+1,cmp);
	for(int i=1;i<=q;i++){
		if(uis[x[i].x])dij(x[i].x);
		ans[i].sum=w[x[i].y]+w[x[i].x]+d[x[i].y];
		ans[i].id=x[i].id;
	}
	sort(ans+1,ans+q+1,cmp1);
	for(int i=1;i<=q;i++)cout<<ans[i].sum<<"\n";
} 
