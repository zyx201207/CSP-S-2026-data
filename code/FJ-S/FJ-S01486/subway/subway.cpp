#include<bits/stdc++.h>
using namespace std;
#define int long long
int dis[505][505];
int a[5000005];
struct we{
	int x,w;
};
vector<we>q[500005],q2[505];
int c,m,n,d,t;
int dfs1(int fa){
	for(auto u:q2[fa])
	for(auto v:q[u.x])
	dis[fa][v.x]=min(dis[fa][v.x],u.w+v.w);
	return 0; 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&m,&n,&d,&t);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	dis[i][j]=1e16;
	for(int i=1;i<=m;i++){
		int k;scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int w,op;scanf("%lld%lld",&op,&w);
			q[op].push_back({i,w});
			q2[i].push_back({op,w});
		}
	}
	for(int i=1;i<=m;i++)dfs1(i);
	for(int k=1;k<=m;k++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=m;i++)dis[i][i]=0;
	while(t--){
		int l,r;
		scanf("%lld%lld",&l,&r);
		int minn=1e16;
		for(auto u:q[l])for(auto v:q[r])
		minn=min(minn,dis[u.x][v.x]+u.w+v.w);
		printf("%lld\n",minn+a[l]+a[r]);
	}
	return 0;
}
