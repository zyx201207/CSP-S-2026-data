#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,INF=1e18+1;
int c,n,m,d,q,w[N],k,u,v,ans;
int l[N][21],t[N][21],cnt[N];
int ti[505][505];
int read(){
	int shu=0;
	char zf=getchar();
	while(zf<'0' or zf>'9'){
		zf=getchar();
	}
	while(zf>='0' and zf<='9'){
		shu=(shu<<3)+(shu<<1)+(zf^48);
		zf=getchar();
	}
	return shu;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){continue;}
			ti[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){w[i]=read();}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			u=read();v=read();
			cnt[u]++;
			l[u][cnt[u]]=i;t[u][cnt[u]]=v;
		}
	}
	for(int i=1;i<=m;i++){
		int up=cnt[i];
		for(int j=1;j<=up;j++){
			for(int p=j+1;p<=up;p++){
				u=l[i][j];v=l[i][p];
				ti[u][v]=ti[v][u]=min(ti[u][v],t[i][j]+t[i][p]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(ti[i][k]!=INF && ti[k][j]!=INF && ti[i][j]>ti[i][k]+ti[k][j]){
					ti[i][j]=ti[i][k]+ti[k][j];
				}
			}
		}
	}
	while(q--){
		ans=0;
		u=read();v=read();
		ans+=w[u]+w[v];
		int use=INF; 
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				use=min(use,t[u][i]+t[v][j]+ti[l[u][i]][l[v][j]]);
			}
		}
		ans+=use;
		printf("%lld\n",ans);
	}
	return 0;
}
