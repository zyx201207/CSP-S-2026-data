#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll infll=1e18;
int c,n,m,d,q,pos;
struct node{
	int u,v,w=inf;
}a[500010]; 
vector<int> e[500010];

int w[500010];
int tmp1[500010];
int tmp2[500010];
bool vis[1010][1010];

ll dijkstra(int u,int v){
	vector<bool> vis2(500010,false);
	vector<ll> dis(500010,infll);
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	dis[u]=0ll;
	q.push({0ll,u});
	while(!q.empty()){
		int st=q.top().second;
		q.pop();
		if(vis2[st]) continue;
		vis2[st]=1;
		for(int i=0;i<e[st].size();i++){
			int en=a[e[st][i]].v;
			int val=a[e[st][i]].w;
			if(dis[en]>dis[st]+val){
				dis[en]=dis[st]+val;
				q.push({dis[en],en});
			}
		}
	}
	return dis[v];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int x=1;x<=k;x++){
			cin>>tmp1[x]>>tmp2[x];
		} 
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){	
				int u=tmp1[x];
				int v=tmp1[y];
				if(!vis[u][v] && !vis[v][u]){
					pos++;
					a[pos].u=u;
					a[pos].v=v;
					a[pos].w=min(a[pos].w,tmp2[x]+tmp2[y]);
					a[pos+200000].u=v;
					a[pos+200000].v=u;
					a[pos+200000].w=min(a[pos+200000].w,tmp2[x]+tmp2[y]);
					e[u].push_back(pos);
					e[v].push_back(pos+200000);
					vis[u][v]=1;
					vis[v][u]=1;
				}else{
					a[pos].w=min(a[pos].w,tmp2[x]+tmp2[y]);
					a[pos+200000].w=min(a[pos+200000].w,tmp2[x]+tmp2[y]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y)+w[x]+w[y]<<'\n';
		
	}
}
