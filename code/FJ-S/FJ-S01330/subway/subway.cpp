#include<bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long LL;
typedef unsigned long long ULL;
const int M=2e4+10;
const int M2=5e8+10;
int c,n,m,d,q,x,y;
int w[M],k[510];
int a[510][M],t[510][M];
int mp[M][M];
int main(){

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i!=j){
				mp[i][j]=M;
			}
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			for(int o=j-1;o>=0;o--){
				int _=a[i][j],__=a[i][o];
				mp[_][__]=mp[__][_]=min(mp[_][__],t[i][o]+t[i][j]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]+mp[x][y]);
	}

	return 0;
}
