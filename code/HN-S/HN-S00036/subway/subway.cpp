#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+5005;
int c,n,m,d,b;
int a[maxn],dis[maxn],vis[maxn];
struct ww{
	int v,w;
	bool operator <(const ww&B)const{
		w<B.w;
	}
};
priority_queue<ww>q;
vector<ww>G[maxn];
void dij(int s,int t){
	for(int i=1;i<=m;i++){
		dis[i]=1e18;
		vis[i]=1;
	}
	q.push({s,0});
	vis[s]=0;
	dis[s]=0;
	while(!q.empty()){
		ww f=q.top();
		q.pop();
		int u=f.v;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v,w=G[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				vis[v]=0;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>b;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int cnt=m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt++;
		for(int j=1;j<=x;j++){
			int v,w;
			cin>>v>>w;
			G[v].push_back({cnt,w});
			G[cnt].push_back({v,w});
		}
	}
	m=cnt;
	for(int i=1;i<=b;i++){
		int s,t;
		cin>>s>>t;
		dij(s,t);
		cout<<dis[t]+a[s]+a[t]<<"\n";
	}
	return 0;
}
