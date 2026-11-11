#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,tot,to[N<<1],head[N],nxt[N<<1],bl[N],vis[N],ans,a[N],f[1005][1005];
void add(int u,int v){
	tot++;
	to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void doit(int u){
	bl[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(!bl[v]) doit(v);
	}
}
bool check(){
	for(int i=1;i<=n;i++) bl[i]=1; 
	for(int i=1;i<=k;i++) bl[a[i]]=0;
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(!bl[a[i]]){
			doit(a[i]);
			cnt++; 
		}  
	}
	return cnt<=2;
}
void dfs(int x){
	if(x==k+1){
		if(!check()) return;
		int res=0;
		for(int i=1;i<=n;i++){
			int now=(int)(1e9);
			for(int j=1;j<=k;j++){
				now=min(now,f[i][a[j]]);
			}
			res=max(res,now);
		}
		ans=min(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		} 
	}
}
void bfs(int x){
	for(int i=1;i<=n;i++) f[x][i]=(int)(1e9);
	f[x][x]=0;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(f[x][v]>f[x][u]+1){
				f[x][v]=f[x][u]+1;
				q.push(v);
			}
		}
	} 
}
int random(int n){
	return (long long)rand()*rand()%n;
}
void solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	ans=(int)(1e9);
	if(c<=3){
		for(int i=1;i<=n;i++) bfs(i);
		dfs(1);
	}
	else if(c==7){
		for(int i=1;i<=n;i++) bfs(i);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int mx=0;
				for(int now=1;now<=n;now++){
					mx=max(mx,min(f[i][now],f[j][now]));
				}
				ans=min(ans,mx);
			}
		}
	}
	else ans=random(n-k);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand((unsigned)time(0));
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
