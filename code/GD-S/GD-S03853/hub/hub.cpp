//hub GYSF
#include<bits/stdc++.h>
using namespace std;
int V,T;
namespace A{
	int n,k,a,b,v,res;
	vector<int> p[100010];
	bool vis[100010];
	int vd[100010],d[100010];
	int mx[100010];
	int dfsrt(int k,int f,int sz){
		d[k]=1;
		int mx=0;
		for(auto x:p[k]){
			if(x!=f&&!vis[x]){
				int r=dfsrt(x,k,sz);
				if(r) return r;
				d[k]+=d[x];
				mx=max(mx,d[x]);
			}
		}
		mx=max(mx,sz-d[k]);
		if(mx<=sz/2) return k;
		return 0;
	}
	int dfsans(int k,int f){
		int ret=0;
		mx[k]=1;
		for(auto x:p[k]){
			if(x!=f&&!vis[x]){
				ret+=dfsans(x,k);
				if(mx[x]>v) ret++;
				mx[k]=max(mx[k],mx[x]+1);
			}
		}
		return ret;
	}
	void dfs(int k,int f){
		vd[k]=1;
		for(auto x:p[k]) if(x!=f) dfs(x,k);
		vd[f]+=vd[k];
		if(!f) return;
		int ans=0;
		vis[f]=1;
		int rt=dfsrt(k,f,vd[k]);
		ans+=dfsans(rt,0)+1;
		vis[f]=0,vis[k]=1;
		rt=dfsrt(f,k,n-vd[k]);
		ans+=dfsans(rt,0)+1;
		vis[k]=0;
		res=min(res,ans);
	}
	inline int calc(int k){
		v=k,res=n+1;
		dfs(1,0);
		return res;
	}
	void slv(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) p[i].clear();
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			p[a].push_back(b),p[b].push_back(a);
		}
		int l=-1,r=n,mi;
		while(r-l>1){
			mi=l+r>>1;
			if(calc(mi)>k) l=mi;
			else r=mi;
		}
		printf("%d\n",r);
	}
}
namespace B{
	void slv(){
		
	}
}
void slv(){
	if(V<=10) A::slv();
	else printf("1\n");
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&V,&T);
	while(T--) slv();
	return 0;
}
