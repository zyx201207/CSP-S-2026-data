#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=505,maxm=5e5;
const int inf=2147483647;
struct eage{int to,nxt,w,n;}e[maxm*21];
int n,m,d,c,q;
int node[maxn];
unsigned ll dis[maxn],vis[maxn],w[maxn],t[25][maxn];
vector <int>g[25][maxm];
priority_queue<int,pair<int,int>,greater<pair<int,pair<int,int> > > >q;

void d(int s){
	for(int i=1;i<=m;i++) {
		dis[i]=inf;
		vis[i]=0;
	}
	dis[s]=0;
	
	q.push({0,{s,n});
	while(!q.empty()){
		auto x=q.top(); q.pop();
		int dist=x.first;
		int u=x.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:g[][u]){
			
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int tmp=0;
		for(int j=1;j<=k;j++){
			int u,tt;
			cin>>u>>tt;
			t[i][u]=tt;
			if(tmp){
				//g[++node[tmp]][tmp].push_back(u);
				//g[++node[u]][u].push_back(tmp);
				
			}tmp=u;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		d(s);
		cout<<dis[t]+w[s]+w[t]<<"\n";
	}
	return 0;
}
