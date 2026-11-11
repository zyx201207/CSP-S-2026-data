#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,d,q;
int c;
vector<pair<int,int> >G[11451451];
int dis[1141541];
int w[1145141];
bool vis[1145141]; 
void spfa(int S){
	queue<int>q;
	q.push(S);
	for(int i=1;i<=2*m+d;i++) vis[i]=0,dis[i]=998244353;
	dis[S]=0;vis[S]=1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		vis[now]=1;
		for(auto next:G[now]){
			int ne=next.first,W=next.second;
			if(dis[ne]>dis[now]+W){
				dis[ne]=dis[now]+W;
				if(!vis[ne])
				q.push(ne);
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,x;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			G[a].push_back({i+m,t}); 
			G[i+m].push_back({a,t});  
		}
	}
	while(q--){
		int S,T;
		cin>>S>>T;
		spfa(S);
		cout<<dis[T]+w[T]+w[S]<<'\n';
	}
	return 0;
}

