#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int x,y;
int w[500005];
vector<pair<int,int>> g[500005],s[500005],z[500005];
vector<pair<int,int>> ask[100005];
int dis[500005],in[500005],ans[100005];
queue<int> qu;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++) cin>>w[i];
	for(register int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(register int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
			z[i].push_back({a,t});
		}
	}
	for(register int i=1;i<=m;i++){
		if(g[i].size()<2) continue;
		for(auto j:g[i]) s[j.first].push_back({i,j.second});
	}
	for(register int i=1;i<=q;i++){
		cin>>x>>y;
		if(x>y) swap(x,y);
		ask[x].push_back({y,i});
	}
	for(register int i=1;i<=m;i++){
		if(ask[i].size()){
			memset(dis,0x3f,sizeof dis);
			memset(in,0,sizeof in);
			dis[i]=0;
			qu.push(i);
			while(!qu.empty()){
				int now=qu.front();
				qu.pop();
				in[now]=0;
				for(auto f:g[now]){
					int j=f.first,k=f.second;
					for(auto h:s[j]){
						int u=h.first,v=h.second;
						if(now==u) continue;
						if(dis[u]>dis[now]+k+v){
							dis[u]=dis[now]+k+v;
							if(!in[u]){
								qu.push(u);
								in[u]=1;
							}
						}
					}
				}
			}
			for(auto j:ask[i]) {
				if(dis[j.first]>4e18)
					for(auto k:z[g[j.first][0].first]) dis[j.first]=min(dis[j.first],dis[k.first]+k.second+g[j.first][0].second);
				ans[j.second]=dis[j.first]+w[j.first]+w[i];
			}
		}
	}
	for(register int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}