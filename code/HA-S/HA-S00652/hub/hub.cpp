#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){char ch=getchar();int f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}ll x=0;while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int c,T;
int n,k;
const int N=1e6+5;
vector<int> e[N];
int fa1[N];
int find(int x){
	if(fa1[x]==x)return x;
	return fa1[x]=find(fa1[x]);
}
bool vis[N];
int fa[N];
void merge(int x,int y){
	int r1=find(x),r2=find(y);
	if(r1!=r2){
		fa1[r1]=r2;
	}
}
bool vis2[N];int dis[N];
int bfs(int s){
	for(int i=1;i<=n;i++)vis2[i]=0;
	vis2[s]=1;dis[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		if(vis[u])return dis[u];
		for(int v:e[u]){
			if(vis2[v])continue;
			vis2[v]=1;dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	return 0;
}
int solve0(int mask){
	for(int i=1;i<=n;i++){
		fa1[i]=i;vis[i]=0;
	}
	for(int i=0;i<n;i++){
		if((mask>>i)&1){
			vis[i+1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		if(vis[fa[i]])merge(fa[i],i);
	}
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		v.emplace_back(find(i));
	}
	int h=unique(v.begin(),v.end())-v.begin();
	if(h>2)return 1e9;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		ans=max(ans,bfs(i));
	}
	return ans;
}
void dfs0(int u){
	for(int v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dfs0(v);
	}
}
int ans;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		if(c<=3){
			dfs0(1);
			ans=1e9;
			for(int mask=0;mask<(1<<n);mask++){
				int cnt1=0;
				for(int i=0;i<n;i++){
					if((mask>>i)&1)cnt1++;
				}
				if(cnt1==k){
					ans=min(ans,solve0(mask));
				}
			}
			write(ans);puts("");
		}
	}
	return 0;
}

