#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,fa[N],bj[N],rt[N],nd[N];
vector<int> mp[N];
void dfs(int u,int ft){
	fa[u]=ft;
	for(auto v:mp[u]) if(v!=ft) dfs(v,u);
}
void solve(int u,int lef,int val,int fr){
	bj[u]+=val;
	if(lef) for(auto v:mp[u]) if(v!=fr) solve(v,lef-1,val,u);
}
int jump(int u,int lef){
	if(fa[u]==0) return u;
	if(!lef) return u;
	return jump(fa[u],lef-1);
}
int tj(int u,int r,int now,int ft){
	int cnt=0;
	for(auto v:mp[now]){
		if(v!=ft){
			cnt+=tj(u,r,v,now);
			if(v!=r) nd[now]|=nd[v];
		}
	}
	return cnt+nd[now];
}
bool check(int lim){
	bool ret=0;
	for(int i=1;i<=n;i++){
		dfs(i,0);
		solve(i,lim,1,i);
		for(int j=1;j<=n;j++) rt[j]=jump(j,lim);
		for(int j=1;j<=n;j++){
			nd[i]=1,nd[j]=1;
			solve(j,lim,1,j);
			for(int k=1;k<=n;k++) if(!bj[k]) nd[rt[k]]=1;
			int v=tj(i,j,i,0);
			if(v<=k) ret=1;
			for(int k=1;k<=n;k++) nd[k]=0;
			solve(j,lim,-1,j);
			if(ret) break;
		}
		solve(i,lim,-1,i);
		if(ret) break;
	}
	return ret;
}
void work(){
	for(int i=1;i<=n;i++) mp[i].clear();
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),mp[u].push_back(v),mp[v].push_back(u);
	int l=0,r=n,mid,ret=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) ret=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ret);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _c,_;
	scanf("%d%d",&_c,&_);
	while(_--) work();
}
