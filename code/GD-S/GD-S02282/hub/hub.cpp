#include<iostream>
#include<vector>
using namespace std;
const int N=1000005,inf=0x3f3f3f3f;
int idx,h[N],fa[N],f[N];
struct Edge{
	int v,nx;
}e[N];
vector<int>ve;
void add(int u,int v){
	e[++idx]={v,h[u]};
	h[u]=idx;
}
int find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void dfs(int u,int fa,int d){
	f[u]=min(f[u],d);
	for(int i=h[u];i;i=e[i].nx){
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u,d+1);
	}
}
void sol(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		idx=0;
		for(int i=1;i<=n;i++)h[i]=0;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		int ans=inf;
		for(int s=0;s<(1<<n);s++){
			int cnt=0;
			for(int u=1;u<=n;u++){
				fa[u]=u;
				f[u]=inf;
				if((s>>(u-1))&1)cnt++;
			}
			if(cnt!=k)continue;
			cnt=0;
			for(int u=1;u<=n;u++){
				if((s>>(u-1))&1){
					for(int i=h[u];i;i=e[i].nx){
						int v=e[i].v;
						if((s>>(v-1))&1){
							int x=find(u),y=find(v);
							if(x!=y){
								fa[x]=y;
								cnt++;
							}
						}
					}
				}
			}
			if(cnt<k-2)continue;//不是两个连通块
//			cout<<s<<' ';
			for(int u=1;u<=n;u++){
				if((s>>(u-1))&1)dfs(u,0,0);
			}
			int sum=0;
			for(int u=1;u<=n;u++)sum=max(sum,f[u]);
			ans=min(ans,sum);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin>>c;
	if(c<=3){
		sol();
		return 0;
	}
	return 0; 
}
/*
0 1
5 2
1 2
2 3
3 4
4 5

1
*/
