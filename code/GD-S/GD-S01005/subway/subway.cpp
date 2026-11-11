#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,Q=1e5+10;
struct Node{
	int v,w;
};
struct plem{
	int id,u,v;
	bool operator < (const plem &o) const {
		return u>o.u;
	}
};
int a[N],dis[N],ans[Q];
vector<Node> G[N];
priority_queue<plem> b;
void dijstkal(int s){
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(s),dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(Node e:G[u]){
			int v=e.v,w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			G[n+i].push_back({v,w});
			G[v].push_back({n+i,w});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		b.push({i,u,v});
	}
	int last=0;
	for(int i=1;i<=q;i++){
		int id=b.top().id,u=b.top().u,v=b.top().v;
		b.pop();
		if(u!=last) dijstkal(u),last=u;
		ans[id]=a[u]+a[v]+dis[v];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
