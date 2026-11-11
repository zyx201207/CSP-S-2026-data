#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int c,T,n,k,p[N],a[N],f[N],ans,dis[N],vis[N];
vector<int>e[N];
void dfs(int x){
	if(x>k){
//		for(int i=1;i<=k;i++)
//			cout<<a[i]<<' ';
//		cout<<'\n';
		for(int i=1;i<=n;i++)
			f[i]=0;
		int cnt=0;
		queue<int>q;
		for(int i=1;i<=k;i++)
			if(!f[a[i]]){
				if(cnt==2)return ;
				++cnt;
				while(!q.empty())q.pop();
				q.push(a[i]);
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(int v:e[u]){
						if(p[v]&&!f[v]){
							f[v]=cnt;
							q.push(v);
						}
					}
				}
			}
		if(!cnt)return ;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		priority_queue<pir,vector<pir>,greater<pir> >Q;
		for(int i=1;i<=n;i++)
			if(p[i]){
				dis[i]=0;
				Q.push({0,i});
			}
			else dis[i]=1e9;
		int res=0;
		while(!Q.empty()){
			int u=Q.top().se,w=Q.top().fi;
			Q.pop();
			if(vis[u])continue;
			vis[u]=1;
			res=max(res,w);
			for(int v:e[u]){
				if(dis[u]+1<dis[v])dis[v]=dis[u]+1,Q.push({dis[v],v});
			}
		}
		ans=min(ans,res);
		return ;
	}
	for(int i=a[x-1]+1;i<=n;i++){
		p[i]=1;
		a[x]=i;
		dfs(x+1);
		p[i]=0;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=1e18;
		for(int i=1;i<=n;i++)
			p[i]=0,a[i]=0;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}

