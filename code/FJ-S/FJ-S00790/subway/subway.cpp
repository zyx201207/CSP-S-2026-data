#include<bits/stdc++.h>
using namespace std;
#define N 510
#define D 30
#define M 500010
int c,n,m,d,q,w[N],pas[M][2],ti[N][N];
bool pa[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			ti[i][j]=0x3fffffff;
		}
	}
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			pas[j][0]=a;
			pas[j][1]=t;
		}
		for(int e=1;e<=k;e++){
			for(int j=e+1;j<=k;j++){
				ti[pas[e][0]][pas[j][0]]=ti[pas[j][0]][pas[e][0]]=min(ti[pas[e][0]][pas[j][0]],pas[e][1]+pas[j][1]);
			}
		}
	}
	for(int i=1;i<=m;i++)
		ti[i][i]=0; 
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(ti[i][k]<0x3fffffff&&ti[k][j]<0x3fffffff)
				ti[i][j]=ti[j][i]=min(ti[i][k]+ti[k][j],ti[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+w[y]+ti[x][y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


