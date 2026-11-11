#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mn 1000006
using namespace std;
long long c,t,n,k,u,v,sz[mn],vis[mn],ff,ans,pv[mn],x,amx[mn],bmx[mn],l;
vector<int> e[mn];
void dfs(int now,int fa){
	pv[now]=1;
	for(int i=0;i<sz[now];i++){
		int v=e[now][i];
		if(v==fa) continue;
		if(!vis[v]) continue;
		dfs(v,now);
	}
}
long long dfs0(int now,int fa){
	if(vis[now]) return 0;
	long long fx=1111111111;
	for(int i=0;i<sz[now];i++){
		int v=e[now][i];
		if(v==fa) continue;
		fx=min(fx,dfs0(v,now)+1);
	}
	return fx;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int rp=1;rp<=t;rp++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			sz[i]=0;
			e[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			sz[u]++;
			sz[v]++;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c<=3){
			ans=1111111111;
			for(int s=0;s<(1<<n);s++){
				ff=0;
				for(int i=0;i<n;i++){
					if(s&(1<<i)) vis[i+1]=1,ff++;
					else vis[i+1]=0;
				}
				if(ff!=k) continue;
				for(int i=1;i<=n;i++) pv[i]=0;
				ff=0;
				for(int i=1;i<=n;i++){
					if((!pv[i])&&(vis[i])){
						dfs(i,0);
						ff++;
					}
				}
				if(ff>2) continue;
				x=0;
				for(int i=1;i<=n;i++) x=max(x,dfs0(i,0));
				ans=min(ans,x);
			}
			cout<<ans<<'\n';
			continue;
		}
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		l=(n-1)/2-1;
		if(k>l){
			cout<<1<<'\n';
			continue;
		}
		cout<<(l+1-k+2*k-1)/(2*k)+1<<'\n';
	}
	return 0;
}
