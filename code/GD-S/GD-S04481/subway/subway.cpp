#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e18+7;
const int N=5e5+7;
struct node{
	int x;
	long long dis;
	bool operator < (const node& i) const {
		return dis>i.dis;
	}
};
int c,n,m,d,Q;
long long dis[507];
long long disa[507];
bool vis[507];
vector<pair<int,long long> > t[N];
vector<pair<int,int> > g[507];
priority_queue<node> q;
void Dijstra(int st,int ed){
	for(int i=1;i<=m;i++) disa[i]=MAX;
	disa[st]=0;
	memset(vis,0,sizeof(vis));
	vis[st]=true;
	for(int i=0;i<t[st].size();i++) q.push({st,dis[st]+t[st][i].second});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		if(now.x==ed) return ;
		for(int i=0;i<t[now.x].size();i++){
			for(auto j:g[t[now.x][i].first]){
				int ty=j.first;
				long long tx=now.dis+j.second;
				cout<<ty<<": "<<tx<<endl;
				if(!vis[ty] && tx<=disa[ty]){
					vis[ty]=true;
					q.push({ty,tx});
					disa[ty]=tx;
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	scanf("%d",&c);
	scanf("%d%d",&n,&m);
	scanf("%d%d",&d,&Q);
	int x;
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		dis[i]=x;
	}
	int u,w;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d%d",&u,&w);
			t[u].push_back({i,w});
			g[i].push_back({u,w});
		}
	}
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		Dijstra(l,r);
		cout<<disa[r]+dis[r]<<endl;
	}
	return 0;
}
