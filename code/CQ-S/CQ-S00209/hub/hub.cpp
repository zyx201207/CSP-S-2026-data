#include<iostream>
using namespace std;
int cid,t;
void solve();
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cid,&t);
	while(t--)solve();
	return 0;
}
int n,k;
int f[106][106][106][3][2];
struct lb{
	int v,n,h;
}q[2000006];
int cnt=1;
void add(int u,int v){
	q[++cnt].v=v;
	q[cnt].n=q[u].h;
	q[u].h=cnt;
	return ;
}
int dis[2000006];
bool bj[2000006];
int mx=0;
int tot=0;
void dfs(int u,int fa){
	if(bj[u])dis[u]=0;
	for(int i=q[u].h;i;i=q[i].n){
		int v=q[i].v;
		if(v==fa)continue;
		dis[v]=dis[u]+1;
		if(bj[v]&&bj[u])tot--;
		dfs(v,u);
		dis[u]=min(dis[u],dis[v]+1);
	}
	mx=max(mx,dis[u]);
//	printf("dis[%d] = %d\n",u,dis[u]);
	return ;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		q[i].h=0;
	}
	cnt=1;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	int res=1e9;
	int m=1<<n;
	for(int i=1;i<m;i++){
		if(__builtin_popcount(i)!=k)continue;
		for(int j=1;j<=n;j++){
			if((i>>j-1)&1){
				bj[j]=true;
			}else bj[j]=false;
		}
		dis[1]=1e9;
		mx=0;
		tot=k;
		dfs(1,0);
		if(tot>2)continue;
//		printf("%d:  %d\n",i,mx);
		res=min(res,mx);
	}
	printf("%d\n",res);
	return ;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
