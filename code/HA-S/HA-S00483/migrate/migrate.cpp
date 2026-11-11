#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int x[1010];
int f[1010],dis[1010];
vector<int> G[1010];
bool bfs(int u,int v){
	for(int i=1;i<=n;i++){
		f[i]=0;
		dis[i]=1e9;
	}
	queue<int> q;
	dis[u]=0;
	q.push(u);
	f[u]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<G[t].size();i++){
			if(dis[G[t][i]]>dis[t]+1){
				dis[G[t][i]]=dis[t]+1;
				f[G[t][i]]=f[t];
				q.push(G[t][i]);
			}
			else if(dis[G[t][i]]==dis[t]+1) f[G[t][i]]+=f[t];
		}
	}
	if(f[v]==2) return true;
	return false;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(x[i]-x[j])<=d){
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(bfs(i,j)) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
