#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,f[1000005],maxx,d[1000005],sum,flag,s;
vector<int> e[1000005];
void dfs(int u,int x,int fa){
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,x,u);
		d[u]=max(d[u],d[v]+1);
	}
	if(d[u]>=x)sum++;
}
void dfs1(int u,int x,int fa){
	if(d[u]<x)return;
	bool yy=1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs1(v,x,u);
		if(d[v]<x)yy=0;
		if(e[u].size()==2){
			f[u]+=f[v];
		}
	}
	if(yy&&e[u].size()==2)f[u]++;
	if(e[u].size()==2)maxx=max(maxx,f[u]);
}
int dfs2(int u,int step,int fa,int x){
	if(d[u]<x||e[u].size()>2||step>x)return 0;
	for(auto v:e[u]){
		if(v==fa||d[v]<x)continue;
		s=v;
		return dfs2(v,step+1,u,x)+1;
	}
	return 0;
}
bool check(int x){
	memset(f,0,sizeof f);
	memset(d,0,sizeof d);
	maxx=0,sum=0;
	dfs(1,x,0);
	if(e[1].size()==1){
		sum-=dfs2(1,1,0,x);
		dfs1(s,x,0);
	}
	else dfs1(1,x,0);
	sum-=min(2*x,maxx);
	return sum<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++)e[i].clear();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int l=1,r=n/2;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		cout<<l<<'\n';
	}
	return 0;
}
