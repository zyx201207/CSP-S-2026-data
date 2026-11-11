#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,k,m,dd,q,t;
int enter[550];
int a[600010];
int d[600010];
bool vis[600010];
struct edge{
	int to,val;
};
int ans[100010];
struct query{
	int l,r,id;
}qu[100010];
bool cmp(query x,query y){
	return x.l<y.l;
}
struct node{
	int cmp;
	int dis;
	bool operator<(node b)const{
		return dis>b.dis;
	}
};
vector<edge>e[600010];
inline void dijkstra(int s){
	priority_queue<node>q1;
	for(int i=1;i<=n*m+m;i++){
		d[i]=1e18;
		vis[i]=0;
	}
	d[s]=enter[s];
	q1.push({s,d[s]});
	while(!q1.empty()){
		int x=q1.top().cmp;
		q1.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(auto p:e[x]){
			int v=p.to,w=p.val;
			if(d[v]>d[x]+w){
				d[v]=d[x]+w;
				q1.push({v,d[v]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>enter[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			if(j!=1){
				e[i*m+a[j-1]].push_back({i*m+a[j],0});
				e[i*m+a[j]].push_back({i*m+a[j-1],0});
			}
			e[a[j]].push_back({i*m+a[j],t});
			e[i*m+a[j]].push_back({a[j],t});
		}
	}
//	cout<<"hello"; 
	for(int i=1;i<=q;i++){
		cin>>qu[i].l>>qu[i].r;
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,cmp);
	int now=0;
	for(int i=1;i<=q;i++){
		if(qu[i].l!=now){
			now=qu[i].l;
			dijkstra(qu[i].l);
		}
		ans[qu[i].id]=d[qu[i].r]+enter[qu[i].r];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
