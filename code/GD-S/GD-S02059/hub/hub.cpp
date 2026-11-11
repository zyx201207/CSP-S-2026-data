#include<bits/stdc++.h>
#define gc getchar
#define pb push_back
using namespace std;
const int N=1e6+5,inf=1e9;
inline void re(int &s){
	s=0;
	char a=gc();
	short f=1;
	while(!isdigit(a)){
		if(a=='-') f=-1;
		a=gc();
	}
	while(isdigit(a)){
		s=(s<<3)+(s<<1)+(a-'0');
		a=gc();
	}
	s*=f;
}
int i,j,n,m,tmp,t,dep[N],sz[N],k;
int x,y,f[N],mx1[N],mx2[N],s,c[N],dis[N];
vector<int>g[N];
long long mx=inf;
bool lian=1,vis[N];
void dfs2(){	
	queue<int>q;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		if(c[i]){
			dis[i]=0;
			q.push(i);
		}
	}
	int u;
	while(!q.empty()){
		u=q.front();
		q.pop();
	//	if(vis[u]) continue;
		for(int v:g[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp=max(tmp,dis[i]);
	}
	mx=min(mx,1LL*tmp);
}
bool ff;
void dfs(int u,int dep,int s){
	if(dep>k){
		for(int i=1;i<=n;i++) dis[i]=inf;
		dfs2();	
//		for(int i=1;i<=n;i++){
//			if(c[i]) cout<<i<<" ";
//		}
//		cout<<mx<<endl;
		return;
	}
	
	for(int i=u+1;i<=n-k+1;i++){
		ff=0;
		for(int j:g[i]) if(c[j]){
			ff=1;
			break;
		} 
		if(s==2&&ff==0) continue;
		c[i]=1;
		if(ff==0) dfs(u,dep+1,s+1);
		else dfs(u,dep+1,s);
		c[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	re(tmp);
	re(t);
	while(t--){
		mx=inf;
		
		memset(dis,0x3f,sizeof dis);
		re(n);
		re(k);
		for(int i=1;i<n;i++){
			re(x),re(y);
			g[x].pb(y);
			g[y].pb(x);
		}
		dfs(0,1,0);
		printf("%lld\n",mx);
		for(int i=1;i<=n;i++) g[i].clear();
		//for(int i=1;i<=n;i++) g[i].
	}
	return 0;
}
