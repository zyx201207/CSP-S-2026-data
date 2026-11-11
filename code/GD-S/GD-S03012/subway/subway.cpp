#include<bits/stdc++.h>
using namespace std;
const int N=500+2e4+10;
const int M=2e4+10;
const int INF=0x3f3f3f3f;
int c,n,m,di,q;
int d[N][N],dout[M];
inline int stan(int x) {
	return x+m;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	cin>>c>>n>>m>>di>>q;
	int nn=n+m;
	for(int i=1;i<=nn;i++){
		d[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&dout[i]);
	}
	for(int i=1;i<=n;i++){
		int stas;
		cin>>stas;
		for(int j=1;j<=stas;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			d[stan(i)][a]=t;
			d[a][stan(i)]=t;
		}
	}
	for(int k=1;k<=nn;k++){
		for(int i=1;i<=nn;i++){
			for(int j=i;j<=nn;j++){
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		int ans=d[x][y]+dout[x]+dout[y];
		printf("%d\n",ans);
	}
	return 0;
}
