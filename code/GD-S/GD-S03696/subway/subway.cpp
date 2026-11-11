#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int read(){
	int x=0,f=1;char op=getchar();
	while(op<'0'||op>'9'){
		if(op=='-') f=-1;
		op=getchar();
	}
	while(op>='0'&&op<='9') x=x*10+(int)(op-'0'),op=getchar();
	return x*f;
}
using namespace std;
const int N=505,M=5e5+5,inf=1e18;
int C,n,m,d,q,tot;
int w[M],len[N];
int dis[N][N];
vector<pii> b[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) w[i]=read();
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		len[i]=read();
		for(int j=1;j<=len[i];j++){
			int x,y;
			x=read(),y=read();
			b[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(pii u:b[i]){
			for(pii v:b[i]){
				if(u.fi!=v.fi){
					dis[u.fi][v.fi]=min(dis[u.fi][v.fi],u.se+v.se);
					dis[v.fi][u.fi]=min(dis[v.fi][u.fi],u.se+v.se);
				}
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}	
	}
	while(q--){
		int x,y,res=inf;
		x=read(),y=read();
		for(pii u:b[x]){
			for(pii v:b[y]){
				res=min(res,u.se+v.se+dis[u.fi][v.fi]);
			}
		}
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}//fc subway.out subway3.ans
