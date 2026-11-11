#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,k,x,y,ans,dis[N];
bool ch[N],vis[N];
vector <int> e[N];
void dfs1(int u){
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(vis[v]||!ch[v]) continue;
		dfs1(v);
	}
}
void dfs2(int u){
	vis[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(vis[v]) continue;
		dis[v]=min(dis[v],dis[u]+1);
		dfs2(v);
	}
}
void choose(int x,int sum){
	if(sum==k){
		int res=0;
		for(int i=1;i<=n;i++){
			if(ch[i]&&!vis[i]){
				dfs1(i);
				res++;
			}
		}
		if(res>2) return ;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			dis[i]=n;
		}
		res=0;
		for(int i=1;i<=n;i++){
			if(!ch[i]) continue;
			for(int j=1;j<=n;j++){
				vis[j]=0;
			}
			dis[i]=0;
			dfs2(i);
		}
		for(int i=1;i<=n;i++){
			res=max(res,dis[i]);
		}
		ans=min(ans,res);
	}
	for(int i=x+1;i<=n;i++){
		ch[i]=1;
		choose(i,sum+1);
		ch[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		ans=n;
		choose(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

