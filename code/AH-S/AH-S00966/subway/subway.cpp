#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct station{
	int di;
	int w[20];
	int t[20];
}u[500005];
struct node{
	int x,y;
	int w;
}f[505];
int fi;
int w[500005];
int k[505];
bool ok[500005];
int a[505][500005];
int t[505][500005];
int x[100005],y[100005];
int dfs(int now,int goal){
	if(now==goal)return 0;
	int min_ans;
	for(int i=1;i<=fi;i++){
		ok[now]==true;
		if(now==f[i].x)min_ans=min(min_ans,t[f[i].w][1]+t[f[i].w][2]+dfs(f[i].y,goal));
		if(now==f[i].y)min_ans=min(min_ans,t[f[i].w][1]+t[f[i].w][2]+dfs(f[i].x,goal));
		ok[now]=false;
	}
	return min_ans;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			u[a[i][j]].w[++u[a[i][j]].di]=i;
			u[a[i][j]].w[u[a[i][j]].di]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++)scanf("%d %d",&x[i],&y[i]);
	if(7<=c<=11){
		for(int i=1;i<=n;i++){
			f[++fi]={a[i][1],a[i][2],i};
		}
		for(int i=1;i<=q;i++)printf("%d\n",dfs(x[i],y[i]));	
				
	 }
	return 0;
}
