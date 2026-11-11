#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
struct node{
	int v;
	long long w;
};
node a[500005];
vector<node> e[505];
bool vis[505];
long long dis[505];
int n,m,c,d,q;
long long w_1[505];
priority_queue<pair<long long,int>> qe;
void dj(int s){
	for(int i=0;i<=m;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	qe.push({0,s});
	while(!qe.empty()){
		auto t=qe.top();
		qe.pop();
		int u=t.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto j:e[u]){
			int v=j.v;
			long long w=j.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qe.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w_1[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last_v=0,last_w=0;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>a[j].v>>a[j].w;

		}
		for(int j=1;j<k;j++){
			for(int l=j+1;l<=k;l++){
				e[a[j].v].push_back({a[l].v,a[l].w+a[j].w});
				e[a[l].v].push_back({a[j].v,a[l].w+a[j].w});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		dj(s);
		long long ans=0;
		ans=dis[e]+w_1[s]+w_1[e];
		cout<<ans<<endl;
	}
	return 0;
}

