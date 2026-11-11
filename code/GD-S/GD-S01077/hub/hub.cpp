#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=(int)b;i>=(int)a;i--)
#define ll long long
#define ull unsigned long long
const int N=1e6+10;
const ll mod=1e9+7;
const ll inf=1e18+10;
using Vl=vector<int>;
using PI=array<int,2>;
int cid,T,n,k,fa[N],dep[N],q[N],ans=0;
Vl g[N];
bool is[N];
inline int fd(int x){return fa[x]==x?x:fa[x]=fd(fa[x]);}
inline void H(int u,int v){
	u=fd(u),v=fd(v);
	if(u!=v) fa[u]=v;
	return ;
}
inline int pfs(int u,int F){
	int d1=0,d2=0;
	for(int v:g[u]) if(v^F){
		int d=pfs(v,u)+1;
		if(d>d1) d2=d1,d1=d;
		else if(d>d2) d2=d;
	}
	ans=max(ans,d1+d2);return d1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>cid>>T;
	while(T--){
		FOR(i,1,n) g[i].clear();
		cin>>n>>k;
		FOR(i,2,n){int u,v;cin>>u>>v;g[u].push_back(v),g[v].push_back(u);}
		if(n<=20){
			ans=mod;
			ROF(S,0,(1<<n)-1) if(__builtin_popcount(S)==k){
				int l=1,r=0;
				FOR(i,1,n){
					is[i]=(S>>(i-1))&1,fa[i]=i;dep[i]=mod;
					if(is[i]) dep[i]=0,q[++r]=i;
				}
				while(l<=r){
					int u=q[l++];
					for(int v:g[u]){
						if(is[u]&&is[v]) H(u,v);
						if(dep[v]>dep[u]+1) dep[v]=dep[u]+1,q[++r]=v;
					}
				}
				int res=0,ct=0;
				FOR(i,1,n){
					if((ct+=(fa[i]==i)&&is[i])>2){res=mod;break;}
					res=max(res,dep[i]);
				}
				ans=min(ans,res);
			}
			cout<<ans<<'\n';continue;
		}
		ans=0;pfs(1,0);
		cout<<ans/3<<'\n';continue;
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
