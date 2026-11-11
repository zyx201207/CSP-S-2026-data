#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,INF=1e18+7;

inline int read(){
	int f=1,x=0;
	char gc=getchar();
	while(gc<'0' || gc>'9'){
		if(gc=='-') f=-1;
		gc=getchar();
	}
	while(gc>='0' && gc<='9'){
		x=x*10+(gc-'0');
		gc=getchar();
	}
	return x*f;
}

struct Egde{
	int to,len;
};
vector<Egde> gg[M];
int c,n,m,d,Q,w[M],g[N][N],x,y,minn,len_1,len_2,u,v,k;

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();m=read();
	d=read();Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int kkk=1;kkk<=n;kkk++){
		k=read();
		for(int j=1;j<=k;j++){
			int id=read(),len_id=read();
			gg[id].push_back({kkk,len_id});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=INF;
			if(i==j) g[i][j]=0;
		}
	}
	for(int id=1;id<=m;id++){
		k=gg[id].size();
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++){
				x=gg[id][i].to;
				y=gg[id][j].to;
				g[x][y]=min(g[x][y],gg[id][i].len+gg[id][j].len);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[j][k]);
			}
		}
	}
	while(Q--){
		u=read();v=read();
		minn=INF;
		len_1=gg[u].size();len_2=gg[v].size();
		for(int i=0;i<len_1;i++){
			for(int j=0;j<len_2;j++){
				x=gg[u][i].to;
				y=gg[v][j].to;
				minn=min(minn,gg[u][i].len+gg[v][j].len+g[x][y]);
			}
		}
		printf("%lld\n",minn+w[u]+w[v]);
	}
	return 0;
}

