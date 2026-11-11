#include<bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define psp putchar(' ')
using namespace std;
const int N=2e5+5;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10){
		putchar(x+'0');
		return;
	}
	print(x/10);
	putchar(x%10+'0');
}
int n,m,k;
int T;
vector<int>a[N];
int vis[N];
int f[N];
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
struct line{
	int u,v;
}L[N];
int con[N];
int dis[N];
int book[N];
void bfs(){
	queue<int>q;
	for(int i=1;i<=n;i++)book[i]=0;
	for(int i=1;i<=n;i++)if(vis[i])book[i]=1,q.push(i),dis[i]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<a[x].size();i++){
			int y=a[x][i];
			if(book[y])continue;
			book[y]=1;
			dis[y]=dis[x]+1;
			q.push(y);
		}
	}
}
int mn=1e18;
void dfs(int x,int cnt){
	if(cnt+(n-x+1)<k)return;
	if(cnt>k)return;
	if(x==n+1){
		if(cnt!=k)return;
		for(int i=1;i<=n;i++)f[i]=i,con[i]=0;
		for(int i=1;i<n;i++){
			int u=L[i].u,v=L[i].v;
			if(!vis[u]||!vis[v])continue;
			f[find(u)]=find(v);
		}
		for(int i=1;i<=n;i++)if(vis[i])con[find(i)]=1;
		int cnt=0;
		for(int i=1;i<=n;i++)cnt+=con[i];
		if(cnt>2)return;
		bfs();
		int sum=0;
		for(int i=1;i<=n;i++)sum=max(sum,dis[i]);
		mn=min(mn,sum);
	}
	vis[x]=0;
	dfs(x+1,cnt);
	vis[x]=1;
	dfs(x+1,cnt+1);
	vis[x]=0;
}
signed main(){
	//ios::sync_with_stdio(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();
	T=read();
	if(c<=3){
		while(T--){
			n=read(),k=read();
			for(int i=1;i<=n;i++)a[i].clear();
			for(int i=1;i<n;i++){
				int u=read(),v=read();
				a[u].push_back(v);
				a[v].push_back(u);
				L[i]={u,v};
			}
			mn=1e18;
			dfs(1,0);
			print(mn),endl;
		}
	}
}

