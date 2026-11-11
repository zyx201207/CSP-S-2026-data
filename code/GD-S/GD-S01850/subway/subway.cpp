#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NN=1e7+5,N=5e5+5,M=1e5+5;
int c,m,n,d,q,a[N],dis[N],vis[N],ans[M],cnt;
struct cc{
	int v,w;
};
vector<cc> g[NN],g1[N];
vector<int> s[N],s1[N];
struct node{
	int u,dis;
	bool operator>(const node&a)const{
		return dis>a.dis;
	}
};
void dijkstra(int st){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<node,vector<node>,greater<node> > q;
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		int u=q.top().u;
		if(vis[u]){
			q.pop();
			continue;	
		}
		vis[u]=1;
		for(int i = 0 ; i < g[u].size() ; i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
struct qq{
	int st,ed,id;
}b[M];
bool cmp(qq x,qq y){
	return x.st<y.st;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> m >> n >> d >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	cnt=n;
	for(int i = 1 ; i <= m ; i++){
		int k;
		cin >> k;
		int v=0,ne=0;
		for(int j = 1 ; j <= k ; j++){
			int u,w;
			cin >> u >> w;
			cnt++;
			if(j!=1){
				g[cnt].push_back({v,0});
				g[v].push_back({cnt,0});
				g[u].push_back({cnt,w});
				g[cnt].push_back({u,w});
			}else{
				g[u].push_back({cnt,w});
				g[cnt].push_back({u,w});
			}
			v=cnt;
			ne=w;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < g1[i].size() ; j++){
			for(int k = 0 ; k < g1[i].size() ; k++){
				int u=g1[i][j].v,w=g1[i][j].w+g1[i][k].w,v=g1[i][k].v;
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	for(int i = 1 ; i <= q ; i++){
		cin >> b[i].st >> b[i].ed;
		b[i].id=i;
	}
	sort(b+1,b+1+q,cmp);
	for(int i = 1 ; i <= q ; i++){
		if(b[i].st!=b[i-1].st){
			dijkstra(b[i].st);
		}
		ans[b[i].id]=dis[b[i].ed]+a[b[i].ed]+a[b[i].st];
	}
	for(int i = 1 ; i <= q ; i++){
		cout << ans[i] << endl;
	}
	return 0;
}
