#include <bits/stdc++.h>

using namespace std;
const int N=105;
int n,k,h[N],cnt,a[N],v[N],ans,as=INT_MAX;
struct Edge{
	int to,nxt;
}e[N];
void add_edge(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
void check(int x,int fa){
	v[x]=1;
	for (int i=h[x];i!=-1;i=e[i].nxt){
		int u=e[i].to;if (u==fa) continue ;
		if (a[u]) check(u,x);
	}
}
void cal(int x,int fa,int dis){
	for (int i=h[x];i!=-1;i=e[i].nxt){
		int u=e[i].to;if (u==fa) continue ;
		if (a[u]) ans=min(ans,dis+1);
		else cal(u,x,dis+1);
	}
}
void dfs(int x){
	if (x==n){
		int tmp=0;
		for (int i=1;i<=n;i++){
			if (a[i]) tmp++;v[i]=0;
		}
		//cout<<n<<" "<<k<<" "<<tmp<<endl;
		if (tmp!=k) return ;tmp=0;
		for (int i=1;i<=n;i++){
			if (a[i]&&(!v[i])) check(i,i),tmp++;
		}if (tmp>2) return ;tmp=0;
		for (int i=1;i<=n;i++){
			if (!a[i]) ans=n+1,cal(i,i,0),tmp=max(tmp,ans);
		}
		as=min(as,tmp);
		return ;
	}
	a[x+1]=0;dfs(x+1);
	a[x+1]=1;dfs(x+1);
}
void work(){
	cin>>n>>k;as=INT_MAX;
	memset(h,-1,sizeof(h));cnt=0;
	for (int i=1;i<n;i++){
		int u,v;cin>>u>>v;add_edge(u,v);add_edge(v,u);
	}
	dfs(0);cout<<as<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;while (t--) work();
	return 0;
}
