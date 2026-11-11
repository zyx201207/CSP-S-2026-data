#include<bits/stdc++.h>
#define int long long
#define endl putchar('\n')
#define psp putchar(' ')
using namespace std;
const int N=1e6+5;
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
int d;
int w[N];
struct val{
	int to,dis;
	friend bool operator<(val a,val b){
		return a.dis>b.dis;
	}
};
vector<val>a[2*N];
int node_num;
void add(int u,int v,int w){
	a[u].push_back(val{v,w});
	a[v].push_back(val{u,w});
}
int dis[N];
int dis_1[1005][1005]; 
int vis[N];
int dfn[N];
int low[N];
int idx;
vector<int>has[N];
stack<int>t;
int rt;
int num;
void tarjan(int fa,int x){
	dfn[x]=low[x]=++idx;
	t.push(x);
	for(int i=0;i<a[x].size();i++){
		int y=a[x][i].to;
		if(y==fa)continue;
		if(!dfn[y]){
			tarjan(x,y);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x]){
				num++;
				while(!t.empty()){
					int kkk=t.top();
					t.pop();
					has[num].push_back(kkk);
					if(kkk==y)break;
				}
				has[num].push_back(x);
			}
		}
		else{
			low[x]=min(low[x],dfn[y]);
		}
	}
}
vector<val>b[N];
int dep[N];
int top[N];
int Fa[N];
int sz[N];
int h[N];
void xfs(int fa,int x){
	dep[x]=dep[fa]+1;
	Fa[x]=fa;
	sz[x]=1;
	for(int i=0;i<b[x].size();i++){
		int y=b[x][i].to;
		int w=b[x][i].dis;
		if(y==fa)continue;
		dis[y]=dis[x]+w;
		xfs(x,y);
		sz[x]+=sz[y];
		if(sz[h[x]]<sz[y])h[x]=y;
	}
}
void dfs(int x,int head){
	top[x]=head;
	if(h[x])dfs(h[x],head);
	for(int i=0;i<b[x].size();i++){
		int y=b[x][i].to;
		if(y==Fa[x]||y==h[x])continue;
		dfs(y,y);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=Fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int dist(int x,int y){
	return dis[x]+dis[y]-2*dis[lca(x,y)];
}
signed main(){
	//ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read();
	n=read(),m=read(),d=read(),T=read();
	for(int i=1;i<=m;i++)w[i]=read();
	if(c<=11){
		int new_node=m;
		for(int i=1;i<=n;i++){
			int K=read();
			new_node++;
			while(K--){
				int to=read(),dis=read();
				add(new_node,to,dis);
			}
		}
		for(int rt=1;rt<=new_node;rt++){
			for(int i=1;i<=new_node;i++)vis[i]=0,dis[i]=1e18;
			dis[rt]=0;
			priority_queue<val>q;
			q.push(val{rt,0});
			while(!q.empty()){
				int x=q.top().to;
				q.pop();
				if(vis[x])continue;
				vis[x]=1;
				for(int i=0;i<a[x].size();i++){
					int y=a[x][i].to;
					int w=a[x][i].dis;
					if(dis[x]+w<dis[y]){
						dis[y]=dis[x]+w;
						if(!vis[y])q.push(val{y,dis[y]});
					}
				}
			}
			for(int i=1;i<=new_node;i++)dis_1[rt][i]=dis[i];
		}
		while(T--){
			int u=read(),v=read();
			print(dis_1[u][v]+w[u]+w[v]),endl;
		}
		return 0;
	}
	if(c<=15){
		int new_node=m;
		for(int i=1;i<=n;i++){
			int K=read();
			new_node++;
			while(K--){
				int to=read(),dis=read();
				add(new_node,to,dis);
			}
		}
		deque<int>q;
		while(T--){
			int u=read(),v=read();
			for(int i=1;i<=new_node;i++)vis[i]=0,dis[i]=1e18;
			dis[u]=0;
			while(!q.empty())q.pop_back();
			q.push_back(u);
			vis[u]=1;
			while(!q.empty()){
				int x=q.front();
				q.pop_front();
				for(int i=0;i<a[x].size();i++){
					int y=a[x][i].to;
					int w=a[x][i].dis;
					if(vis[y])continue;
					vis[y]=1;
					dis[y]=dis[x]+w;
					if(w!=0)q.push_back(y);
					else q.push_front(y);
				}
			}
			print(dis[v]+w[u]+w[v]),endl;
		}
		return 0;
	}
	if(c<=19){
		int new_node=m;
		int con=0;
		for(int i=1;i<=n;i++){
			int K=read();
			new_node++;
			while(K--){
				int to=read(),dis=read();
				add(new_node,to,dis);
				con=dis;
			}
		}
		tarjan(1,1);
		for(int i=1;i<=num;i++){
			for(int j=0;j<has[i].size();j++){
				int x=has[i][j];
				b[x].push_back(val{i+new_node,con});
				b[i+new_node].push_back(val{x,con});
			}
		}
		xfs(1,1);
		dfs(1,1);
		while(T--){
			int u=read(),v=read();
			print(dist(u,v)+w[u]+w[v]),endl;
		}
	}
}
