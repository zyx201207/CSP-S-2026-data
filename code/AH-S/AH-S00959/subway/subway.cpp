#include<bits/stdc++.h>
using namespace std;
#define N 505
#define T 500005
#define ll long long
int c,n,k,d,q,s[T],x[T],p,u,v;
ll a[N][N],f[N][N],t,ans;
struct nd{
	int d;
	ll t;
}b[T][25];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&k,&d,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=1ll*N*T*T;
	for(int i=1;i<=k;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		while(u--){
			scanf("%d %lld",&p,&t);
			b[p][++x[p]].d=i;
			b[p][x[p]].t=t;
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=x[i];j++)
			for(int l=1;l<j;l++){
				u=b[i][j].d;
				v=b[i][l].d;
				a[u][v]=a[v][u]=min(a[v][u],b[i][j].t+b[i][l].t);
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			f[i][j]=a[i][j];
		f[i][i]=0;
	}
	for(int l=1;l<=n;l++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
	while(q--){
		scanf("%d %d",&u,&v);
		ans=1ll*N*T*T;
		for(int i=1;i<=x[u];i++)
			for(int j=1;j<=x[v];j++){
				nd l=b[u][i],r=b[v][j];
				ans=min(ans,f[l.d][r.d]+l.t+r.t);
			}
		cout<<ans+s[u]+s[v]<<endl;
	}
	return 0;
}
