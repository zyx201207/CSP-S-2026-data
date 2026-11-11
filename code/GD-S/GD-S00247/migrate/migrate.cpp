#include<bits/stdc++.h>
using namespace std;
const int N=10;
int c,t,n;
int vis[N],a[N][N],dep[N];
long long d;
long long x[N];
vector<int> e[N];
void bfs(int x){
	for(int i=1;i<=n;i++) dep[i]=15;
	for(int i=1;i<=n;i++) vis[i]=0;
	queue<int> q;
	q.push(x);
	dep[x]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:e[u]){
			if(dep[u]+1==dep[v]) a[x][v]=a[v][x]=1;
			else if(dep[v]>dep[u]+1){
				dep[v]=dep[u]+1,q.push(v);
				if(a[u][x]) a[v][x]=a[x][v]=1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(abs(x[i]-x[j])<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++) bfs(i);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++) ans+=a[i][j];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
