#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int type,t,n,k,d[N],lst[N],tot=0,a[N];
vector<int>g[N];
bool vis[N];
void dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		d[v]=d[u]+1;
		dfs(v,u);
	}
}
bool dfs0(int u,int fa,int rt){
	if(rt==u){
		vis[u]=1,lst[++tot]=u;
		return true;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa)continue;
		if(dfs0(v,u,rt))vis[u]=1,lst[++tot]=u;
	}
	return vis[u];
}
int dfs1(int u,int fa,int dep){
	int res=dep;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa||vis[v])continue;
		res=max(res,dfs1(v,u,dep+1));
	}
	return res;
}
struct node{
	int l,r;
	bool operator <(const node &b)const{
		return l<b.l;
	}
}now[N];
int mmm[N];
bool solve(int x){
	tot=0;
	for(int i=1;i<=n;i++)d[i]=vis[i]=0;
	dfs(1,0);
	int mx=0,p=0,q=0;
	for(int i=1;i<=n;i++)mx=max(mx,d[i]);
	for(int i=1;i<=n;i++)if(mx==d[i])p=i;
	for(int i=1;i<=n;i++)d[i]=0;
	dfs(p,0),mx=0;
	for(int i=1;i<=n;i++)mx=max(mx,d[i]);
	for(int i=1;i<=n;i++)if(mx==d[i])q=i;
	dfs0(p,0,q);
	for(int i=1;i<=n;i++)if(vis[i])d[i]=dfs1(i,0,0);
	for(int i=1;i<=tot;i++)a[i]=d[lst[i]];
	for(int i=1;i<=tot;i++){
		if(a[i]>x)return false;
		a[i]=x-a[i];
	}
	if(tot<=k)return true;
	p=tot+1,q=0;
	for(int i=1,sum=n;i<=tot;i++){
		sum=min(sum,a[i]+i);
		if(sum==i){
			p=i;
			break;
		}
	}
	for(int i=tot,sum=0;i;i--){
		sum=max(sum,i-a[i]);
		if(sum==i){
			q=i;
			break;
		}
	}
	if(p>=q||q-p+1<=k)return true;
	int cnt=0;
	for(int i=p+1;i<=q-1;i++){
		int l=max(p,i-a[i]),r=min(q,i+a[i]);
		now[++cnt]={l,r};
	}
	sort(now+1,now+1+cnt);
	mmm[cnt+1]=q;
	for(int i=cnt;i>=1;i--)mmm[i]=min(mmm[i+1],now[i].r);
	now[0].l=p;
	int ans=n;
	for(int i=0;i<=cnt;i++){
		ans=min(ans,(now[i].l-p+1)+(q-mmm[i+1]+1));
	}
	return ans<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >>type>>t;
	while(t--){
		cin >>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin >>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		int l=0,r=n,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(solve(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout <<ans<<"\n";
	}
	return 0;
}
