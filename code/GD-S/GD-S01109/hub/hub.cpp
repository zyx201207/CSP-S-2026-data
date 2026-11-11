#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int C,T,n,k,c[N],cp[N],d[N],ans;
vector<int>v[N];
queue<int>q;
bool vis[N];
void bfs(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(c[i]) q.push(i),vis[i]=1,d[i]=0;
		else vis[i]=0;
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		res=max(res,d[x]);
		for(auto y:v[x]){
			if(!vis[y]) vis[y]=1,d[y]=d[x]+1,q.push(y);
		}
	}
	ans=min(ans,res);
}
void dfz(int x){
	for(auto y:v[x]) if(cp[y]) cp[y]=0,dfz(y);
}
void dfs(int x,int d){
	if(x>n){
		if(d!=k) return;
		int cnt=0;
		for(int i=1;i<=n;i++) cp[i]=c[i];
		for(int i=1;i<=n;i++) if(cp[i]) cp[i]=0,dfz(i),cnt++;
		if(cnt==2) bfs();
		return;
	}
	dfs(x+1,d);
	if(d<k) c[x]=1,dfs(x+1,d+1),c[x]=0;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k,ans=1e18;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y),v[y].push_back(x);
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
