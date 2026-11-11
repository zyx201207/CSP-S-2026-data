#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,k,vis[N],col[N],dis[N];	
vector<int>f[N];
void dfs(int u,int fa){
	for(int i=0;i<f[u].size();i++){
		int v=f[u][i];
		if(v==fa||!col[v])continue;
		else{
			vis[v]=1;dfs(v,u);
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c>3){
			cout<<1<<'\n';continue;
		}
		cin>>n>>k;
		for(int i=1;i<=n;i++)f[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			f[u].push_back(v);f[v].push_back(u); 
		}
		int ans=1e18;
		for(int i=0;i<(1<<n);i++){
			int sum=0;
			for(int j=1;j<=n;j++){
				vis[j]=0;dis[j]=1e18;
				col[j]=((i>>(j-1))&1);
				if(col[j]==1)sum++,dis[j]=0;
			}
//			for(int j=1;j<=n;j++)cout<<col[j];
//			cout<<' '<<sum<<' '<<k<<'\n';
			if(sum!=k)continue;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(col[j]&&!vis[j]){
					vis[j]=1;
					cnt++;dfs(j,-1);
				}
			}
//			for(int j=1;j<=n;j++)cout<<col[j];
//			cout<<" "<<cnt<<'\n';
			if(cnt>2)continue;
			queue<int>q;
			for(int j=1;j<=n;j++){
				vis[j]=0;
				if(col[j]){
					vis[j]=1;dis[j]=0;
					q.push(j);
				}
			}
			while(q.size()){
				int u=q.front();q.pop();
				for(int i=0;i<f[u].size();i++){
					int v=f[u][i];
					if(vis[v])continue;
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						vis[v]=1;
						q.push(v);
					}				
				}
			}
			int res=0;
			for(int j=1;j<=n;j++)res=max(res,dis[j]);
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
   return 0;
}


