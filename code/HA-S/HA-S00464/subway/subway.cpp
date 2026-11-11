#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N=505;
const int M=500005;

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void prin(ll x){
	if(x<10){
		putchar(x+'0');
		return;
	}
	prin(x/10);
	putchar(x%10+'0');
}
int c,n,m,d,q;
int w[M];
int v[M][25],g[M][25],deg[M];
ll dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1,k,a,t;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a=read();t=read();
			v[a][++deg[a]]=i;
			g[a][deg[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=deg[i];j++){
			for(int k=j+1;k<=deg[i];k++){
				int x=v[i][j];
				int a=g[i][j];
				int y=v[i][k];
				int b=g[i][k];
				dis[x][y]=dis[y][x]=min(dis[x][y],1ll*a+b);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int x,y;
	while(q--){
		x=read();y=read();
		ll minn=1e18;
		for(int i=1;i<=deg[x];i++){
			for(int j=1;j<=deg[y];j++){
				minn=min(minn,1ll*g[x][i]+g[y][j]+dis[v[x][i]][v[y][j]]);
			}
		}
		prin(minn+w[x]+w[y]);
		putchar('\n');
	}
	return 0;
}
