//subway.cpp
#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,a[1005][1005],w[100005],vis[1005][1005];
long long dfs(int st,int fn){
	if(st==fn) return 0;
	long long out=INT_MAX;
	for(int i=1;i<=m;i++){
		if(a[st][i]&&vis[st][i]==0){
			vis[st][i]=1,vis[i][st]=1;
			out=min(out,dfs(i,fn)+a[st][i]);
			vis[st][i]=0,vis[i][st]=0;
		}
	}
	return out;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int t; scanf("%d",&t);
		int b[1005],c[1005];
		for(int j=1;j<=t;j++){
			scanf("%d%d",&b[j],&c[j]);
			if(a[b[1]][b[j]]==0) a[b[1]][b[j]]=c[j]+c[1];
			else a[b[1]][b[j]]=min(c[j]*2,a[b[1]][b[j]]);
		}
	}
	for(int i=1;i<=m;i++){
		a[i][i]=INT_MAX;
		for(int j=1;j<=m;j++){
			if(a[i][j]&&a[j][i]==0) a[j][i]=a[i][j];
		}
	}
	long long ans;
	while(q--){
		ans=0;
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=dfs(x,y);
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
