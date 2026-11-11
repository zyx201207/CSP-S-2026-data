#include<bits/stdc++.h>
using namespace std;
struct yst{
	long long t,qx,zx;
}dis[505][505],a,b;
long long aaa,n,m,d,q,z[505],t[505][505],s[505],p[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>aaa>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j)
			dis[i][j].t=INT_MAX;
			t[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&p[i]);
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			scanf("%lld",&z[j]);
			scanf("%lld",&t[i][z[j]]);
		}
		for(int j=1;j<=k;j++){
			for(int w=1;w<=k;w++){
				dis[z[j]][z[w]].t=0;
				dis[z[j]][z[w]].zx=dis[z[j]][z[w]].qx=i;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j].t==0){
					continue;
				}
				a=dis[i][k],b=dis[k][j];
				if(dis[i][j].t>a.t+b.t+t[a.zx][k]+t[b.qx][k]){
					dis[i][j].t=a.t+b.t+t[a.zx][k]+t[b.qx][k];
					dis[i][j].qx=a.qx;
					dis[i][j].zx=b.zx;
				}
			}
		}
	}
	while(q--){
		long long c,d;
		scanf("%lld %lld",&c,&d);
		printf("%lld\n",dis[c][d].t+p[c]+p[d]+t[dis[c][d].qx][c]+t[dis[c][d].zx][d]);
	}
	return 0;
}
