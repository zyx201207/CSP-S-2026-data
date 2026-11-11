#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 5e5 + 1e3;
int n,m,t,a[N],dis[N],vis[N];
vector<PII> e[N];
void djs(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[x]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,x});
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto nt:e[u]){
			int v = nt.first;
			int w= nt.second;
			if(dis[v]>dis[u]+w&&!vis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, d;
	cin >> c >> n >> m >> d >> t;
	for(int i = 1; i<= m; i ++){
		cin>>a[i];
	}
	for(int i= 1;i<=n;i++){
		int k;
		cin>>k;
		int x,y;
		for(int j =1;j<=k;j++){
			cin >> x>>y;
			e[i].push_back({500+x,y});
			e[500+x].push_back({i,y});
		}
	}
	while(t--){
		int aa, b;
		cin>>aa>>b;
		djs(aa+500);
		cout<<dis[b+500]+a[aa]+a[b]<<'\n';
	}
	return 0;
}
