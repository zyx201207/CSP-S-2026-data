#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,T,n,k,u,v,col[N],an,fa[N],dis[N],g,di2[N];
vector<int>G[N];
void dfs(int u){
	for(int i:G[u]){
		if(i==fa[u])continue;
		fa[i]=u;
		dfs(i);
	}
}
void df3(int x){
	col[x-1]=0;
	for(int i:G[x]){
		if(col[i-1])df3(i);
	}
}
void df2(int x){
	if(col[x-1])df3(x),g++;
	for(int i:G[x]){
		if(i!=fa[x])df2(i);
	}
}
void df4(int x,int f){
	for(int i:G[x]){
		if(i!=f){
			di2[i]=di2[x]+1;
			df4(i,x);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		dfs(1);an=n;
		if(c<=3){
			for(int i=1;i<(1<<n);i++){
				int x=0,cn=0;
				for(int j=0;j<n;j++){
					if((1<<j)&i){
						col[j]=1;
						x++;
					}else col[j]=0;
				}
				g=0;df2(1);
				if(x==k&&g<=2){
					for(int j=0;j<n;j++){
						if((1<<j)&i){
							col[j]=1;
							x++;
						}else col[j]=0;
						dis[j+1]=n+1;
					}
					for(int j=1;j<=n;j++){
						for(int k=1;k<=n;k++)di2[k]=0;
						df4(j,0);
						for(int k=1;k<=n;k++)if(col[k-1])dis[j]=min(dis[j],di2[k]);
					}
					for(int i=1;i<=n;i++)cn=max(cn,dis[i]);
					an=min(an,cn);
				}
			}
			printf("%d\n",an);
		}else if(c==7){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(k==1)j=i;
					int x=0,cn=0;
					col[i]=col[j]=1;
					for(int k=1;k<=n;k++)di2[k]=0;
					df4(i,0);
					for(int k=1;k<=n;k++)dis[k]=di2[k],di2[k]=0;
					if(i!=j)df4(j,0);
					for(int k=1;k<=n;k++)dis[k]=min(dis[k],di2[k]);
					for(int i=1;i<=n;i++)cn=max(cn,dis[i]);
					an=min(an,cn);
					col[i]=col[j]=0;
					if(k==1)break;
				}
			}
			printf("%d\n",an);
		}
	}
	return 0;
}
