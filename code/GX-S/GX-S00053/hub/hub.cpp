#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n,k,mx[N],cnt;
set<int> e[N];
vector<int> stk,ve;

void dfs_init(int u,int fa,int u_){
	stk.push_back(u);
	if(u==u_) ve=stk;
	for(auto v:e[u]) if(v!=fa){
		dfs_init(v,u,u_);
	}
	stk.pop_back();
}

void dfs1(int u,int fa,int val){
	mx[u]=0;
	for(auto v:e[u]) if(v!=fa){
		dfs1(v,u,val);
		mx[u]=max(mx[u],mx[v]+1);
	}
	cnt+=(mx[u]>=val);
//	printf("#%d %d\n",u,mx[u]);
}

inline int Cnt(int u,int mid){
	cnt=0;
	dfs1(u,0,mid);
	return cnt;
}

bool check(int mid,int u,int v){
	int res=Cnt(u,mid)+Cnt(v,mid);
//	printf("%d %d\n",mid,res);
	return res<=k;
}

inline void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].insert(v);
		e[v].insert(u);
	}

	int ans=n+1;
	for(int u=1;u<=n;u++) for(int v=1;v<=n;v++) if(v!=u){
		stk.clear();
		ve.clear();
		dfs_init(u,0,v);
		int sz=ve.size();
		e[ve[sz/2-1]].erase(ve[sz/2]);
		e[ve[sz/2]].erase(ve[sz/2-1]);

		int l=-1,r=n+1;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid,u,v)) r=mid;
			else l=mid;
		}
		ans=min(ans,r);
//		printf("%d %d\n",ve[sz/2-1],ve[sz/2]);
//		printf("%d %d %d\n\n",u,v,r);

		e[ve[sz/2-1]].insert(ve[sz/2]);
		e[ve[sz/2]].insert(ve[sz/2-1]);
	}
	printf("%d\n",ans);

	for(int i=1;i<=n;i++)
		e[i].clear();
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,tt;
	scanf("%d%d",&c,&tt);
	while(tt--){
		solve();
//		return 0;
	}
}
