#include<bits/stdc++.h>
using namespace std;
const int N=1505;
struct A{
	int id;
	int v;
};
int w[N];
int f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	int c,n,m,dian,q; scanf("%d%d%d%d%d",&c,&n,&m,&dian,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=1503;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,v; scanf("%d%d",&a,&v);
			f[m+i][a]=v;
			f[a][m+i]=v;
		}
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]+w[x]+w[y]);
	}
	return 0;
}
