#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,k;
int dis[N],ans[N],dep[N];
vector<int>e[N];
void dfs(int u,int fa){
	dis[u]=dis[fa]+1;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
vector<int>p;
void dfs1(int u,int fa,int mid){
	dep[u]=0;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs1(v,u,mid);
		dep[u]=max(dep[v]+1,dep[u]);
	}
	if(dep[u]==mid)p.push_back(u);
}
bool check(int mid){
	p.clear();dfs1(1,0,mid);
	if(p.size()==1){
//		dfs(p[0],0);
		dfs1(p[0],0,mid);
	}
	if(p.size()==0)return 1;
	if(p.size()>2)return 0;
	if(p.size()==2){
		dis[0]=-1;
		dfs(p[0],0);
		for(int i=1;i<=n;i++)ans[i]=dis[i];
		dis[0]=-1;
		dfs(p[1],0);
		for(int i=1;i<=n;i++)if(ans[i]>mid&&dis[i]>mid)return 0;
		return 1;
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int x,y,i=1;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	if(k==1){
		dis[0]=-1;
		dfs(1,0);
		int rt=0,mx=0;
		for(int i=1;i<=n;i++)if(dis[i]>mx)rt=i,mx=dis[i];
		dis[0]=-1;dfs(rt,0);
		for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
		cout<<(mx+1)/2<<"\n";
	} 
	if(k==2){
		int l=1,r=n,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))res=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<res<<"\n";
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
