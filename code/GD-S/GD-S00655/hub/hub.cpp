#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;bool flg=0; 
	char c='?';
	while(c<'0'||c>'9'){
		c=getchar();
		if(c=='-')flg=1;
	}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	if(flg)x=-x;
	return;
}
int c;
int n,k,tg,dep[1005],dis[1005],len,f[1005];
vector<int>g[1005];
bool flg[1005];
int tp,st[1005];
void dfs(int x,int fa){
	st[++tp]=x;
	if(x==tg){
		for(int i=1;i<=tp;i++){
			dis[st[i]]=i-1;
			flg[st[i]]=1;
		}
		len=tp-1;
	}
	for(auto u:g[x])
		if(u!=fa)dfs(u,x);
	tp--;
}
void dfs2(int x,int fa){
	f[x]=fa;
	dep[x]=1;
	for(auto u:g[x])
		if(u!=fa)if(!flg[u]){
			dfs2(u,x);
			dep[x]=max(dep[x],dep[u]+1);
		}
}
int qwq(int x,int y){
	for(int i=1;i<=n;i++)flg[i]=0;
	tg=y;
	dfs(x,0);
	for(int i=1;i<=n;i++)
		if(flg[i])dfs2(i,0);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(flg[i])
			if((i!=x)&&(i!=y))ans=max(ans,min(dis[i]-1,len-dis[i]-1)+dep[i]);
	priority_queue<pair<int,int> >q;
	for(auto u:g[x])
		if(!flg[u])q.push({dep[u],u});
	for(auto u:g[y])
		if(!flg[u])q.push({dep[u],u});
	q.push({0,0});
	int K=k-2;
	while(K--){
		if(q.empty()){
			q.push({0,0});
			break;
		}
		pair<int,int>p=q.top();q.pop();
		for(auto u:g[p.second])
			if(u!=f[p.second])q.push({dep[u],u});
	}
//	cout<<x<<" "<<y<<" "<<ans<<" "<<q.top().first<<'\n';
	return max(ans,q.top().first);
}
void solve(){
	for(int i=1;i<=n;i++)g[i].clear();
	read(n),read(k);
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		g[u].push_back(v),g[v].push_back(u);
	}
	if(k==n){
		cout<<0<<'\n';
		return;
	}
	int ans=n;
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)ans=min(ans,qwq(i,j));
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	read(c),read(T);
	while(T--)solve();
	return 0;
}
