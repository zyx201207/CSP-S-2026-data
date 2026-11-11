#include<bits/stdc++.h>
#define fir first
#define se second
#define debug(x) cerr<<#x<<':'<<(x)<<endl;
using namespace std;
typedef pair<int,int> pii;
const int N=4005;
int c,t;
int n,k,dep[N],indep[N];
bool col[N];
vector<int> g[N];
vector<pii > e;
bool dfs(int u,int fa,int r){
	if(dep[u]>=r)col[u]=1;
//	debug(dep[u]);
	bool tmp=1;
	for(int v:g[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		tmp=dfs(v,u,r)&&tmp;
		indep[u]=max(indep[u],indep[v]+1);
	}
//	debug(indep[u]);
	if(tmp&&indep[u]<r)col[u]=0;
	return !col[u];
//	if(g[u].empty())indep[u]=0;
}
int count(int u,int fa){
	int res=0;
	if(col[u])res++;
	for(int v:g[u]){
		if(v==fa)continue;
		res+=count(v,u);
	}
	return res;
}
inline bool check(int r){
//	int tmp=n;
	for(int i=1;i<=n;i++)
		dep[i]=indep[i]=col[i]=0;
	for(pii u:e){
		int x=u.fir,y=u.se;
		dep[x]=dep[y]=0;
		dfs(x,y,r);dfs(y,x,r);
		int res=count(x,y)+count(y,x);
//		tmp=min(res,tmp);
		if(res<=k)return 1;
	}//debug(tmp);
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		e.clear();
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e.push_back({u,v});
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int l=0,r=n,mid;
//		for(int i=0;i<=n;i++)check(i);
		while(l<r){
			mid=l+r>>1;
			if(check(mid)){
				r=mid;
			}else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
