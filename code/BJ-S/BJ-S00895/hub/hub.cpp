#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define LL __int128
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
inline ll read(){
	ll k=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	if(f)return -k;else return k;
}
inline char readc(){
	char c=getchar();
	while(!isgraph(c))c=getchar();
	return c;
}
inline string reads(){
	string s="";char c=getchar();
	while(!isgraph(c))c=getchar();
	while(isgraph(c)){s+=c;c=getchar();}
	return s;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar((x%10)^48);
	return ;
}
const int N=2e6+10;
int n,k,fa[N],son[N],top[N],siz[N],dep[N];
vector<int>g[N];
set<int>st;
bool vis[N];
void dfs(int x,int f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	for(int i:g[x]){
		if(i==f)continue;
		dfs(i,x);
		siz[x]+=siz[i];
		if(siz[son[x]]<siz[i])son[x]=i;
	}
	return ;
}
void dfs2(int x,int tp){
	top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(int i:g[x]){
		if(i==fa[x]||i==son[x])continue;
		dfs2(i,i);
	}
	return ;
}
int lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void dfs3(int x,int f){
	if(vis[x]||st.find(x)==st.end())return ;
	vis[x]=1;
	for(int i:g[x]){
		if(i==f)continue;
		dfs3(i,x);
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		n=read();k=read();
		for(int i=0;i<=n;++i)fa[i]=siz[i]=son[i]=dep[i]=top[i]=0,g[i].clear();
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1,0);
		dfs2(1,1);
		int ans=1e9;
		for(int o=0;o<(1<<n);++o){
			int cnt=0;
			for(int i=0;i<n;++i){
				if((o>>i)&1)++cnt;
			}
			if(cnt!=k)continue;
			st.clear();
			cnt=0;
			for(int i=0;i<n;++i){
				if((o>>i)&1){
					st.insert(i+1);
				}
				vis[i+1]=0;
			}
			bool ok=1;
			for(int i=1;i<=n;++i){
				if(!vis[i]&&st.find(i)!=st.end()){
					if(cnt==2){
						ok=0;
						break;
					}
					dfs3(i,0),++cnt;
				}
			}
			if(!ok)continue;
			int res=0;
			for(auto i:st){
				for(int j=1;j<=n;++j){
					int L=lca(i,j);
					res=max(res,dep[i]+dep[j]-dep[L]*2);
				}
			}
			ans=min(ans,res);
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
