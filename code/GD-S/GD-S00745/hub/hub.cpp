#include<bits/stdc++.h>
using namespace std;
const int N=1000010,inf=1e9;
vector<int> v[N];
int d[N];
int n,k;
queue<int> q;
pair<int,int> bfs(int x){
	q.push(x);
	for(int i=1;i<=n;i++) d[i]=inf;
	d[x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto i:v[u]) if(d[i]==inf) d[i]=d[u]+1,q.push(i); 
	}
	int mx=-1,p=0;
	for(int i=1;i<=n;i++) if(mx<d[i]) mx=d[i],p=i;
	return make_pair(p,mx);
}
vector<int> rot;
int x,y;
bool dfs1(int u,int pre){
	if(u==y){
		rot.push_back(u);
		return 1;
	}
	for(auto i:v[u]) if(i!=pre && dfs1(i,u)){
		rot.push_back(u);
		return 1;
	}
	return 0;
}
int rt;
int vis[N];
int dep[N];
int f[N][25];
void dfs2(int u,int pre){
	f[u][0]=pre;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto i:v[u]) if(i!=pre) dep[i]=dep[u]+1,dfs2(i,u);
}
int get(int x,int d){
	for(int i=20;i>=0;i--) if((d>>i)&1) x=f[x][i];
	return x;
}
void dfs3(int u,int pre){
	for(auto i:v[u]) if(i!=pre){
		dfs3(i,u);
		if(vis[i] && vis[u]==0) vis[u]=1;
	}
}
int dp[N]; 
void dfs4(int u,int pre){
	int cnt=0,son=0;
	for(auto i:v[u]) if(i!=pre){
		dfs4(i,u);
		if(vis[i]) cnt++,son=i;
	}
	if(cnt==1 && vis[u]!=2) dp[u]=dp[son]+1;
}
bool check(int mid){
	for(int i=1;i<=n;i++)
		vis[i]=0;
	for(int i=1;i<=n;i++) vis[get(i,min(dep[i],mid))]=2;
	dfs3(1,0);
	int cnt=0;
	for(int i=1;i<=n;i++) if(vis[i]) cnt++;
	for(int i=1;i<=n;i++) dp[i]=0;
	dfs4(1,0);
	for(int i=1;i<=n;i++) if(cnt-dp[i]<=k) return 1;
	return 0;
}
int solve(int u){
	rt=u,dfs2(rt,0);
	int l=0,r=n;
	int ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y),v[y].push_back(x);
		}
		x=bfs(1).first,y=bfs(x).first;
		rot.clear();
		dfs1(x,0);
		int ans=1e9;
		int len=rot.size();
		for(int i=max(0,len/2-2);i<min(len,len/2+3);i++)
			ans=min(ans,solve(rot[i]));
		cout<<ans<<endl;
	}
	return 0;
}

