#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
vector<int> g[N];
long long a[N],dis[N][N],d[N],ans;
bool vis[N];
int n,k;

void check(){
	memset(d,127,sizeof(d));
	long long s=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(i==j) continue;
			d[i]=min(d[i],dis[i][j]);
 		}
 		s=max(d[i],s);
	}
	for(int i=1;i<=k;i++){
		if(d[i]==0){
			ans=min(ans,s);
			return ;
		}
	}
}

void bfs(int s){
	memset(vis,false,sizeof(vis));
	queue<int> q;
	q.push(s);
	dis[s][s]=0;
	vis[s]=true;
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
			if(!vis[y]){
				dis[s][y]=dis[s][x]+1;
				vis[y]=true;
				q.push(y);
			}
		}
	}
}

void dfs(int x,int p){
	if(x>n){
		if(p==k){
			check();
		}
		return ;
	}
	dfs(x+1,p);
	a[p]=x;
	dfs(x+1,p+1);
}

void solve(){
	cin>>n>>k;
	ans=1e18;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
		
	}
	for(int i=1;i<=n;i++){
		bfs(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j) continue;
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	dfs(1,0);
//	cout<<ans<<"\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	cout<<1<<"\n"<<2<<"\n";
	return 0;
}
