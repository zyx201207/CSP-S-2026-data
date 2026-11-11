#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
vector<int>vc[N];
int vis[N];
long long dis[N];
int mark[N];
long long ans;
long long maxx=0;
void check(int u,int fa){
	mark[u]=1;
	dis[u]=0;
	for(int i=0;i<vc[u].size();i++){
		int v=vc[u][i];
		if(v==fa) continue;
		if(vis[v]) continue;
		check(v,u);
		if(dis[v]+1>dis[u]){
			maxx=max(maxx,dis[u]+dis[v]+1);
			dis[u]=dis[v]+1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		ans=INF;
		for(int i=1;i<(1<<n);i++){
			memset(vis,0,sizeof(vis));
			vector<int>g;
			int x=i;
			int cnt=0;
			int num=0;
			while(x>0){
				if(x&1){
					vis[cnt+1]=1;
					num++;	
					g.push_back(cnt+1);
				} 
				x>>=1;
				if(num>k) break;
				cnt++;
			}
			if(num!=k) continue;
			memset(mark,0,sizeof(mark));
			cnt=0;
			int flag=1;
			maxx=0;
			for(int i=0;i<g.size();i++){
				if(!mark[g[i]]) {
					cnt++;
					if(cnt>2)  {
						flag=0;
						break;
					}
					check(g[i],-1);
				}
			}
			if(cnt>2) continue;
			ans=min(ans,maxx);
		}
		cout<<ans<<endl;
	} 
	return 0;
}
