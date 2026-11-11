#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pair;
const int N=5e5+5,M=505;
int c,n,m,d,q;
ll dis[M][M];
int w[N],cnt[N],t[N][25],v[N][25];
int read(){
	int x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read();
			v[x][++cnt[x]]=i;
			t[x][cnt[x]]=read();
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int x=v[i][j],y=v[i][k];
				ll len=t[i][j]+t[i][k];
				dis[x][y]=min(dis[x][y],len);
				dis[y][x]=min(dis[y][x],len);
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
		int x=read(),y=read();
		ll ans=1e18;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,dis[v[x][i]][v[y][j]]+t[x][i]+t[y][j]+w[x]+w[y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
Meumy
*/

