#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int num[N],c[N];
vector<int> g[N];
void dfs(int u,int f,int x){
	c[u]=min(c[u],x);
	for(int i=0;i<int(g[u].size());i++){
		int v=g[u][i];
		if(v==f) continue;
		dfs(v,u,x+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int cid,T;
	scanf("%d%d",&cid,&T);
	while(T--){
		int n,k,u,v,ans=1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v),g[v].push_back(u);
		}
		if(n<=10){
			for(int i=0;i<(1<<n);i++){
				int s=0,s1=0,maxn=0;
				for(int j=1;j<=n;j++) num[j]=(i>>(j-1))&1,s+=num[j];
				if(s!=k) continue;
				for(int j=1;j<=n;j++) c[j]=1e9;
				for(int j=1;j<=n;j++)
					if(num[j]){
						dfs(j,0,0);
						for(int z=0;z<g[j].size();z++) s1+=num[g[j][z]];
					}
				for(int j=1;j<=n;j++) maxn=max(maxn,c[j]);
				if(s-s1/2<=2) ans=min(ans,maxn);
			}
			printf("%d\n",ans);
		}
		else{
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++){
					int maxn=0;
					for(int z=1;z<=n;z++) c[z]=1e9;
					dfs(i,0,0),dfs(j,0,0);
					for(int z=1;z<=n;z++) maxn=max(maxn,c[z]);
					ans=min(ans,maxn);
				}
			printf("%d\n",ans);
		}
	}
	return 0;
}
