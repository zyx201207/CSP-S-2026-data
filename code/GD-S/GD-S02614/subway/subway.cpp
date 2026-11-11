#include<bits/stdc++.h>
using namespace std;
const int N=1e5+101;
long long c,n,m,d,r,k[N],w[N],x[N],y[N],vis[N],mn=5*1e5+101;
struct node{
	long long a,t;
}q[10000][10000];
void dfs(long long x,long long y,long long sum){
	if(x==y){
		sum+=w[y];
		mn=min(mn,sum);
		return;
	}
	for(int i=1;i<=k[x];i++){
		if(vis[q[x][i].a]==0){
			vis[q[x][i].a]=1;
			dfs(q[x][i].a,y,sum+q[x][i].t);
			vis[q[x][i].a]=0;
		}
	}
	return; 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&r);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&q[i][j].a,&q[i][j].t);
		}
	}
	for(int i=1;i<=r;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=r;i++){
		mn=5*1e5+101; 
		memset(vis,0,sizeof(vis));
		dfs(x[i],y[i],w[x[i]]);
		printf("%lld\n",mn);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
