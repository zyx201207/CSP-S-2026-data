#include<cstdio>
using namespace std;
const int xm=5e5+5,xn=505,INF=1e9+5;
int c,n,m,d,q,w[xm],k,x,y,a[xm],t[xm],mapp[xn][xn];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) mapp[i][j]=INF;
	}
	if(c<7){
		
	}
	else if(c<12){
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			for(int j=1;j<=k;j++) scanf("%d%d",&a[j],&t[j]);
			mapp[a[1]][a[2]]=mapp[a[2]][a[1]]=t[1]+t[2];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					mapp[j][k]=mapp[k][j]=min(mapp[j][k],mapp[j][i]+mapp[i][k]);
				}
			}
		}
		while(q--){
			scanf("%d%d",&x,&y);
			printf("%d\n",w[x]+w[y]+mapp[x][y]);
		}
	}
	return 0;
}
