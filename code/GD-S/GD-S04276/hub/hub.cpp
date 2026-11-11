#include<bits/stdc++.h>//Çå¿Õ¶à²â 
using namespace std;
#define int long long
bool st;
const int inf=2e18;
const int N=4e3+5;
const int M=8e3+5;
int n,k,ans,res;
struct edge{
	int v,nxt;
}e[M];
int cnt,head[N];
int U[N],V[N];
void ins(int u,int v){
	e[++cnt]={v,head[u]};
	head[u]=cnt; 
}
int fl[N];
int dep[N],vis[N]; 
void bz(int u){
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v]||!fl[v]) continue;
		bz(v);
	}
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++){
		if(fl[i]&&!vis[i]){
			bz(i);
			cnt++;
		}
	} 
	if(cnt<=2) return 1;
	return 0;
} 
void calc(){
	if(!check())return;
	for(int i=1;i<=n;i++)dep[i]=inf; 
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(fl[i]){
			q.push(i);
			dep[i]=0;
		}
	}
	int mx=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dep[v]>dep[u]+1){
				dep[v]=dep[u]+1;
				mx=max(mx,dep[v]);
				q.push(v);
			}
		} 
	}
	ans=min(ans,mx);
//	cout<<mx<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<dep[i]<<" ";
//	}cout<<'\n';
//	for(int i=1;i<=n;i++){
//		cout<<fl[i]<<" ";
//	}cout<<'\n';
}
void dfs(int x,int y){
	if(y==k){
		calc();
		return;
	}
	if(x>n) return;
	fl[x]=1;
	dfs(x+1,y+1);
	fl[x]=0;
	dfs(x+1,y);
} 
void sol_bl(){
	ans=inf;cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		ins(u,v);
		ins(v,u);
		U[i]=u,V[i]=v;
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
bool ed;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	cerr<<(&st-&ed)/1024.0/1024.0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) sol_bl();
}
