#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[500005],tt,idd[1000005],dis[1000005],ans[100005];
bool vis[1000005];
vector<pair<int,int>>g[1000005];
priority_queue<pair<int,int>>qu;
struct anss{
	int uu,vv,idd;
}s[100005];
bool cmp(anss a,anss b){
	return a.uu<b.uu;
}
int main(){
	freopen("subway.in","r",stdin);//44
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int tt=m;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int i=1;i<=n;i++){
		int x;cin>>x;
		vector<int>aa;
		for (int j=1;j<=x;j++){
			int u,w;
			cin>>u>>w;
			tt++;
			idd[tt]=u;
			aa.push_back(tt);
			g[u].push_back({tt,w});
			g[tt].push_back({u,w});
		}
		for (int u:aa){
			for (int v:aa){
				if(u!=v){
					g[u].push_back({v,0});
					g[v].push_back({u,0});
				}
			}
		}
	}
	for (int i=1;i<=q;i++){
		cin>>s[i].uu>>s[i].vv;
		s[i].idd=i;
	}
	sort(s+1,s+q+1,cmp);
	for (int i=1;i<=q;i++){
		if(s[i].uu!=s[i-1].uu){
			memset(dis,0x3f3f3f3f,sizeof dis);
			qu.push({0,s[i].uu});
			dis[s[i].uu]=0;
			while(!qu.empty()){
				int u=qu.top().second;
				qu.pop();
				vis[u]=0;
				for (pair<int,int>xx:g[u]){
					int v=xx.first,w=xx.second;
					if(vis[v])continue;
					if(dis[u]+w<dis[v]){
						dis[v]=dis[u]+w;
						vis[v]=1;
						qu.push({-dis[v],v});
					}
				}
			}
		}
		ans[s[i].idd]=dis[s[i].vv]+a[s[i].uu]+a[s[i].vv];
	}
	for (int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
