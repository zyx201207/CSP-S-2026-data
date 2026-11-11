#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5;
const int INF=0x3f3f3f3f;
int w[N],k[N];
vector<pair<int,int> >G[N];
vector<pair<int,int> >a[N];
int len[N];
void add(int x,int y,int u,int v){
	G[x].push_back({u,y+v});
	G[u].push_back({x,y+v});
}
int dest;
void dfs(int cur,int fa,int dis){
	if(cur==dest){
		return;
	}
	if(len[dest]&&dis>=len[dest]){
		return;
	}
	for(auto u:G[cur]){
		int x=u.first,y=u.second;
		if(x==fa){
			continue;
		}
		if(dis+y<len[x]||!len[x]){
			len[x]=dis+y;
			dfs(x,cur,dis+y);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:a[i]){
			for(auto x:a[i]){
				if(u!=x){
					add(x.first,x.second,u.first,u.second);
				}
			}
		}
	}
	while(q--){
		fill(len+1,len+1+n,0);
		int x,y;
		cin>>x>>y;
		for(auto u:a[x]){
			add(x+n,0,u.first,u.second);
		}
		for(auto u:a[y]){
			add(y+n,0,u.first,u.second);
		}
		dest=y+n;
		dfs(x+n,0,0);
		cout<<len[y+n]+w[x]+w[y]<<"\n";
		for(auto u:a[x]){
			G[x+n].pop_back();
			G[u.first].pop_back();
		}
		for(auto u:a[y]){
			G[y+n].pop_back();
			G[u.first].pop_back();
		}
		len[x+n]=0;
		len[y+n]=0;
	}
	return 0;
}

