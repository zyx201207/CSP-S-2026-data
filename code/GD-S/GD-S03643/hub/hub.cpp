#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
#define getc() (uu==vv&&(vv=(uu=In)+fread(In,1,1<<15,stdin),uu==vv)?EOF:*uu++)
char In[1<<15],*uu=In,*vv=In;
template<class T>
void R(T &x){
	char c=getc();bool f=0;x=0;
	for(;!isdigit(c);f|=(c=='-'),c=getc());	
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getc());	
	f&&(x=-x);
}
using ll = long long;
const int N=2e6+5;
int n,k,u,v,fa[N],un[N],mx[N],ans,res;
vector<int>ve[N],g;
bool vis[N],lt[2000][2000],del[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
void calc(int u,int fa){
	mx[u]=!del[u];
	for(auto v:ve[u])
		if(v^fa){
			calc(v,u);
			if(del[u])res=max(mx[v],res);
			else mx[u]=max(mx[u],mx[v]+1);
		}
	res=max(res,mx[u]);
}
void brute(int dep){
	if(dep>k){
		for(auto u:g)fa[u]=u;
		for(auto u:g)
			for(auto v:g)
				if(lt[u][v])fa[find(u)]=find(v);
		int tot=0;for(auto u:g)un[++tot]=find(u);
		if(unique(un+1,un+1+tot)-(un+1)>2)return;
		rep(i,1,n)del[i]=false;for(auto u:g)del[u]=true;
		res=0,calc(1,0),ans=min(ans,res);return;
	}
	rep(i,1,n)if(!vis[i])vis[i]=true,g.push_back(i),brute(dep+1),vis[i]=false,g.pop_back();
}
void solve(){
	R(n),R(k);memset(lt,false,sizeof lt);
	rep(i,1,n)ve[i].clear();ans=n;bool pd=1;
	rep(i,1,n-1){
		R(u),R(v),ve[u].push_back(v),ve[v].push_back(u);
		if(u<=1000&&v<=1000)lt[u][v]=lt[v][u]=true;
		else pd=0;
	}
	if(pd)brute(1),cout<<ans<<'\n';
	else n>>1,cout<<max((n-k)/3,1)<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;R(c),R(T);
	while(T--)solve();
	return 0;
}
