#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll N=505,M=500005,D=25,inf=1299508350939999;
ll qread(){
	ll rtn=0,fh=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')fh=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		rtn=rtn*10+c-'0';
		c=getchar();
	}
	return fh*rtn;
}
ll minl(ll x,ll y){
	return x>y?y:x;
}
int c,n,m,d,q;
int S=500002,T=500003;
ll a[M][D],t[M][D],cnt[M];
ll w[M],vis[N][N],f[N][N],ans,mx;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int kt,at,tt,u,v,x,y;
	for(int i=1;i<=m;i++){
		w[i]=qread();
	} 
	for(int i=1;i<=n;i++){
		kt=qread();
		for(int j=1;j<=kt;j++){
			at=qread(),tt=qread();
			cnt[at]++;
			a[at][cnt[at]]=i;
			t[at][cnt[at]]=tt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)vis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=2;j<=cnt[i];j++){
			u=a[i][j];
			for(int k=1;k<j;k++){
				v=a[i][k];
				vis[u][v]=vis[v][u]=minl(vis[u][v],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=vis[i][j];
		}
	}
	for(int k=n;k>=1;k--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=minl(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		x=qread(),y=qread();
		ans=w[x]+w[y];
		mx=inf;
		for(int i=1;i<=cnt[x];i++){
			u=a[x][i];
			for(int j=1;j<=cnt[y];j++){
				v=a[y][j];
				mx=minl(mx,f[u][v]+t[x][i]+t[y][j]);
			}
		}
		ans+=mx;
		cout<<ans<<'\n';
	}
	return 0;
} 

























