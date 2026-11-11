#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
int x[N];
vector<int> g[N];
void adde(int a,int b){
	g[a].push_back(b);
	g[b].push_back(a);
}
int dis[N],pt[N];
bool vis[N];
void dij(int u){
	memset(dis,0x3f,sizeof dis);
	memset(pt,0,sizeof pt);
	memset(vis,0,sizeof vis);
	dis[u]=0,pt[u]=1;
	for(int i=1;i<n;i++){
		int t=0,dt=0x3f3f3f3f;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<dt) t=j,dt=dis[j];
		vis[t]=true;
		for(int j=0;j<g[t].size();j++){
			int v=g[t][j];
			if(v>=u&&!vis[v]){
				int nl=dis[t]+1;
				if(nl<dis[v]) dis[v]=nl,pt[v]=pt[t];
				else if(nl==dis[v]) pt[v]+=pt[t];
			}
		}
	}
}
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=i-1;j>0;j--){
			if((x[i]-x[j])<=d) adde(i,j);
			else break;
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		dij(i);
		for(int j=i+1;j<=n;j++)
			if(pt[j]==2) ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
