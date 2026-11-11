#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define ll long long
#define frp freopen
#define fio(in,out) frp(in,"r",stdin),frp(out,"w",stdout)
void bug(){cout<<endl;}
template<typename T,typename ... Ts>
void bug(T x,Ts ... y){cout<<x<<" ",bug(y...);}
template<typename T=int>
T read(){
	T res=0,f=1;char c;
	for(;(c=getchar())<'0'||c>'9';c=='-'?f=-f:0);
	while(c>='0'&&c<='9')res=(res<<3)+(res<<1)+c-'0',c=getchar();
	return res*f;
}
int n,k,ans=1e9,fa[maxn],dis[maxn];
vector<int>g[maxn];
bool vis[maxn],is[maxn];
int find(int x){return x!=fa[x]?fa[x]=find(fa[x]):x;}
void uni(int x,int y){
	if(find(x)==find(y))return;
	fa[find(x)]=find(y);
}
void dfs(int x,int t){
	if(t>k)return;
	if(t==k){
		int cnt=0;
		for(int i=1;i<=n;++i)fa[i]=i;
		for(int i=1;i<=n;++i)if(vis[i]){
			for(int v:g[i])if(vis[v]){
				uni(v,i);
			}
		}
		for(int i=1;i<=n;++i)if(find(i)==i){
			cnt+=vis[i];
		} 
		if(cnt>2)return;
		int nw=0;
		for(int i=1;i<=n;++i)if(!vis[i]){
			queue<int>q;
			for(int j=1;j<=n;++j)is[j]=0;
			int s=0;
			q.push(i),dis[i]=0,is[i]=1; 
			while(q.size()){
				int u=q.front();q.pop();
				if(vis[u])
				{
					s=dis[u];
					break;
				}
				for(int v:g[u])if(!is[v])
					dis[v]=dis[u]+1,q.push(v),is[v]=1;
			}
			nw=max(nw,s);
		}
		ans=min(ans,nw); 
		return;
	}
	if(x>n)return;
	vis[x]=1,dfs(x+1,t+1),vis[x]=0;
	vis[x]=0,dfs(x+1,t);
} 
int main(){
	fio("hub.in","hub.out");
	read();
	int i,T=read(),u,v;
	while(T--){
		n=read(),k=read();ans=1e9;
		for(i=1;i<=n;++i)g[i].clear();
		for(i=1;i<n;++i)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

