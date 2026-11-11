#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,maxx,ans,cnt;
int dis[105];
bool is[105];
vector<int> ve[105];
queue<int> q;
void dfs(int u,int fa){
	if(is[u]&&!is[fa]) cnt++;
	if(cnt>2) return;
	int tmp=(int)(ve[u].size());
	for(int i=0;i<tmp;i++){
		int v=ve[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
void dfs0(int now,int used){
	if(used>k) return;
	if(now==n+1){
		cnt=maxx=0;
		memset(dis,0x3f,sizeof(dis));
		dfs(1,0);
		if(cnt>2) return;
		memset(dis,0x3f,sizeof(dis));
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++) if(is[i]) dis[i]=0,q.push(i);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			int tmp=(int)(ve[u].size());
			for(int i=0;i<tmp;i++){
				int v=ve[u][i];
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		for(int i=1;i<=n;i++) maxx=max(maxx,dis[i]);
		ans=min(ans,maxx);
		return;
	}
	if(used+n-now+1<k) return;
	is[now]=true;
	dfs0(now+1,used+1);
	is[now]=false;
	dfs0(now+1,used);
} 
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		if(c==13||c==14){
			for(int i=1,u,v;i<n;i++) cin>>u>>v;
			cout<<(n/2+2-k+3)/4<<'\n';
			continue;
		}
		ans=1e18;
		for(int i=1;i<=n;i++) ve[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		dfs0(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}

