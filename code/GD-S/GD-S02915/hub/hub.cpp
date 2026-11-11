#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=15;
int c,t,n,k,ans,f[N];
bool vis[N],vis2[N];
vector<int>e[N];
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
inline bool chk(){
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)if(vis[i])
		for(int j:e[i])if(vis[j])
			f[find(i)]=find(j);
	int cnt=0;
	for(int i=1;i<=n;i++)if(vis[i])
		cnt+=f[i]==i;
	return cnt<3;
}
inline int cal(int x){
	queue<pair<int,int> >q;q.emplace(x,0);memset(vis2,0,sizeof vis2);vis2[x]=1;
	while(1){
		int u=q.front().first,d=q.front().second;q.pop();
		for(int i:e[u])if(!vis2[i]){
			if(vis[i])return d+1;
			vis2[i]=1;q.emplace(i,d+1);
		}
	}
}
void dfs(int x,int cnt){
	if(x>n){
		if(cnt==k&&chk()){
			int mx=0;
			for(int i=1;i<=n;i++)
				if(!vis[i])mx=max(mx,cal(i));
			ans=min(ans,mx);
		}
		return;
	}
	dfs(x+1,cnt);vis[x]=1;
	dfs(x+1,cnt+1);vis[x]=0; 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		ans=n;dfs(1,0);cout<<ans<<endl;
	}
	return 0;
}
