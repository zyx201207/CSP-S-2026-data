#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,ans,cnt,vis[2000007],f[2000007],cc,dis[2000007],s[2000007],ss[2000007],sum;
vector<int> g[2000007];
struct node {
	int u,w;
};
void dfs(int uu){
	if(!vis[uu]) return ;
	for(int i=0;i<g[uu].size();i++){
		int aa=g[uu][i];
		if(!f[aa]){
			f[aa]=1;
			dfs(aa);
		}
	}
}
bool check(){
	cc=0;
	for(int i=1;i<=n;i++) f[i]=0;
	for(int i=1;i<=n;i++){
		if(!f[i]&&vis[i]==1){
			cc++;
			f[i]=1;
			dfs(i);
		}
		if(cc>k) return 0;
	}
	if(cc<=k) return 1;
	return 0;
}
int bfs(int u){
	for(int i=1;i<=n;i++) ss[i]=0;
	vector<node> q;
	q.push_back({u,0});
	while(!q.empty()){
		int uu=q[0].u,ww=q[0].w;
		q.erase(q.begin());
		if(vis[uu]) return ww;
		for(int j=0;j<g[uu].size();j++){
			int v=g[uu][j];
			if(!ss[v]){
				ss[v]=1;
				q.push_back({v,ww+1});
			}
		}
	} 
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//Oct31==Dec25?
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		//for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=2;i<=(1<<n);i++){
			cnt=0;
			for(int j=0;(1<<j)<=i;j++){
				if(i&(1<<j)) {
					cnt++;
				}
				if(cnt>k) break;
			}
			if(cnt==k){
				for(int j=1;j<=n;j++) vis[j]=0;
				for(int j=0;(1<<j)<=i;j++){
					if(i&(1<<j)) {
						vis[j+1]=1;
					}
				}
				if(check()){
					sum=0;
					for(int i=1;i<=n;i++){
						if(vis[i]!=1){
							sum=max(sum,bfs(i));
						}  
					}
					ans=min(ans,sum);
				}
				//cout<<"*"<<i<<' '<<sum<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
