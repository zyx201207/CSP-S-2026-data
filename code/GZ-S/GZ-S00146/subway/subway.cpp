//GZ-S00146 贵阳市第九中学 向一坤 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pi pair<int,int>
#define fs first
#define sc second
const int N=509,M=5e5+9;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M];
int k[N];vector<pi> vec[N];
vector<pi> dt[M];
ll dis[N][N];
void FLOYD(){
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i) dis[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)dt[i].size();++j){
			for(int k=0;k<j;++k){
				int u=dt[i][j].fs,v=dt[i][k].fs;
				dis[u][v]=dis[v][u]=dt[i][j].sc+dt[i][k].sc;
				}}}
	
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}}}
	return ;
}
int main(){//O(m*d^2+n^3+q*d^2)=5e5*4e2+1e5*4e2=
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//READ 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];++j){
			int ai,ti;scanf("%d%d",&ai,&ti);
			vec[i].push_back({ai,ti});
			dt[ai].push_back({i,ti});
		}
	}
	//READ
	FLOYD();//O(m*d^2+n^3)
	while(q--){//O(q*d^2)
		int x,y;ll ans=inf;scanf("%d%d",&x,&y);
		for(auto u : dt[x]){
		int xu=u.fs,xval=u.sc;
		for(auto v : dt[y]){
			int yu=v.fs,yval=v.sc;
			ans=min(ans,dis[xu][yu]+w[x]+w[y]+xval+yval);
			//printf("%d %d-> %lld+%lld+%lld\n",xu,yu,w[x]+w[y],xval+yval,dis[xu][yu]);
		}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*注意到n<=500 每条线路的步行时间考虑用floyd计算 
wc!!! 15:52 AC T2
*/ 
