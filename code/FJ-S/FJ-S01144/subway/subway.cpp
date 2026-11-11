#include<bits/stdc++.h>
#define ll long long
#define INF 1e16
using namespace std;
const int N=510,M=5e5+10,D=21;
int w[M],k[N];
vector<int>a[N],t[N];
int num[M],arr[M][D],ti[M][D];
ll dis[N][N];
int read(){
	char ch;
	while((ch=getchar())&&(!isdigit(ch)));
	int x=ch^48;
	while((ch=getchar())&&isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
	}
	return x;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		a[i].push_back(0),t[i].push_back(0);
		for(int j=1,x,y;j<=k[i];j++){
			x=read(),y=read();
			a[i].push_back(x),t[i].push_back(y);
			arr[x][++num[x]]=i;
			ti[x][num[x]]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dis[i][j]=INF;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int u=1,x,w;u<=k[i];u++){
			x=a[i][u],w=t[i][u];
			for(int v=1,j,ww;v<=num[x];v++){
				j=arr[x][v],ww=ti[x][v];
				dis[i][j]=dis[j][i]=min(dis[i][j],1ll*w+ww);
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
	while(q--){
		int x=read(),y=read();
		ll ans=w[x]+w[y],sum=INF;
		for(int i=1;i<=num[x];i++){
			for(int j=1;j<=num[y];j++){
				sum=min(sum,ti[x][i]+ti[y][j]+dis[arr[x][i]][arr[y][j]]);
			}
		}
		printf("%lld\n",ans+sum);
	}
	return 0;
}
