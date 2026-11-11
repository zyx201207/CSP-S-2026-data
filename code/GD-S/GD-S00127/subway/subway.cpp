#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
#define fi first
#define se second
#define eb emplace_back
inline int read(){
	int t=1,c=getchar(),res=0;
	for(;!isdigit(c);c=getchar())if(c=='-')t=-t;
	for(;isdigit(c);c=getchar())res=(res<<1)+(res<<3),res+=c^48;
	return res*t;
}
inline void write(int num){
	if(num<0)putchar('-'),num=-num;
	if(num>9)write(num/10);
	putchar('0'+num%10);
	return;
}
const int N=500,M=5e5;
int dis[N+7][N+7];
int c,n,m,d,q;
vector<pii>p[M+7];
int w[M+7];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			p[a].eb(i,t);
		}
		for(int j=1;j<=i;j++){
			dis[i][j]=dis[j][i]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<p[i].size();j++){
			for(int k=0;k<j;k++){
				dis[p[i][j].fi][p[i][k].fi]=
				dis[p[i][k].fi][p[i][j].fi]=
				min(dis[p[i][j].fi][p[i][k].fi],
				p[i][j].se+p[i][k].se);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<i;k++){
				dis[i][j]=dis[j][i]=
				min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
		for(int j=1;j<i;j++){
			for(int k=1;k<j;k++){
				dis[j][k]=dis[k][j]=
				min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int ans=1e18,u=read(),v=read();
		for(int i=0;i<p[u].size();i++){
			for(int j=0;j<p[v].size();j++){
				ans=min(ans,p[u][i].se+p[v][j].se+dis[p[u][i].fi][p[v][j].fi]);
			}
		}
		write(ans+w[u]+w[v]),putchar('\n');
	}
	return 0;
}
