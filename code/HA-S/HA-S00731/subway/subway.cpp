#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=500001,N=501;
int n,m,q;
int w[M];
map<int,ll>t[N];
vector<int>p[M];
ll ta[N][N];
ll di[N][N];
void f(int x,int y,ll z){
	ta[x][y]=min(ta[x][y],z);
}
void g(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	di[i][j]=ta[i][j];
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	di[i][j]=min(di[i][j],di[i][k]+di[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ta,0x3f,sizeof ta);
	int _;
	scanf("%d%d%d%d%d",&_,&n,&m,&_,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		int k;
	 	scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a1,t1;
			scanf("%d%d",&a1,&t1);
			p[a1].push_back(i);
			t[i][a1]=t1;
		}
	}for(int i=1;i<=n;i++) f(i,i,0);
	for(int k=1;k<=m;k++){
		int len=p[k].size();
		for(int i=1;i<=len;i++)
		for(int j=i+1;j<=len;j++){
			int u=p[k][i-1];
			int v=p[k][j-1];
			ll x=t[u][k]+t[v][k];
			f(u,v,x);
			f(v,u,x);
		}
	}g();
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=LONG_LONG_MAX;
		for(int i=1;i<=p[x].size();i++)
		for(int j=1;j<=p[y].size();j++){
			int u=p[x][i-1],v=p[y][j-1];
			ans=min(ans,di[u][v]+t[u][x]+t[v][y]);
		}printf("%lld\n",ans+w[x]+w[y]);
	}fclose(stdin);fclose(stdout);
	return 0;
}