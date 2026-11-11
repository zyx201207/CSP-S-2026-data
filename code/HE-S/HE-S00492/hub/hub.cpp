#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,k;
vector<int> e[N];
int f[N],dis1[N],dis2[N];
inline void dfs1(int x=1,int fr=-1){
	for (int y:e[x])
		if (y!=fr){
			dis1[y]=dis1[x]+1;
			f[y]=x;
			dfs1(y,x);
		}
}
inline void dfs2(int x,int fr=-1){
	for (int y:e[x])
		if (y!=fr){
			dis2[y]=dis2[x]+1;
			dfs2(y,x);
		}
}
struct DSU{
	int fa[N];
	inline void init(){
		for (int i=1;i<=n;i++) fa[i]=i;
	}
	inline int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	inline void merge(int x,int y){
		x=find(x);y=find(y);
		if (x!=y) fa[y]=x;
	}
}dsu;
inline void solve1(){
	cin>>n>>k;int ans=n+1;
	for (int i=1,x,y;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	f[1]=n+1;
	dfs1();
	for (int s=1;s<(1<<n);s++){
		for (int i=1;i<=n;i++) dis1[i]=0x3f3f3f3f;
		dsu.init();
		int cnt=0;for (int i=1;i<=n;i++)
			cnt+=((s>>(i-1))&1);
		if (cnt!=k) continue;
		for (int i=1;i<=n;i++)
			if (((s>>(i-1))&1)&&((s>>(f[i]-1))&1))
				dsu.merge(i,f[i]);
		int pp=0;
		for (int i=1;i<=n;i++)
			if (((s>>(i-1))&1)&&dsu.find(i)==i) ++pp;
		if (pp>2) continue;
		for (int i=1;i<=n;i++)
			if ((s>>(i-1))&1){
				dis2[i]=0;dfs2(i);
				for (int j=1;j<=n;j++)
					dis1[j]=min(dis1[j],dis2[j]);
			}
		int res=0;
		for (int i=1;i<=n;i++) res=max(res,dis1[i]);
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	for (int i=1;i<=n;i++){
		e[i].clear();
		dis1[i]=dis2[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;
	while (T--) solve1();
	return 0;
}
