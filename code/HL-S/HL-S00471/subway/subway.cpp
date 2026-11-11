#include<bits/stdc++.h>

using namespace std;
const int N= 5e5+10;
int z,n,m,t,q,w[N],d[N];
int a[510][N],b[10010][10010];
bool g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&z,&n,&m,&t,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	
	int same=-99;
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[i][x]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]!=0){
				for(int k=1;k<=m;k++){
					if(a[j][k]!=0){
						b[i][k]=a[j][i]+a[j][k];
						b[k][i]=a[j][i]+a[j][k];
						if(k ==i){
							b[i][k]=a[j][i];
							b[k][i]=a[j][i];
						}
					}
					
				}
			}
		}
	}
	
	
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		int u = w[x]+w[y];
		memset(d,0x3f,sizeof(d));
		memset(g,0,sizeof(g));
		d[x]=0;
		for(int i=1;i<=m;i++){
			int mi=-1;
			for(int j = 1;j<=m;j++){
				if(!g[j]&&(mi==-1||d[mi]>d[j])){
					mi=j;
				}
			}
			g[mi]=true;
			for(int j=1;j<=m;j++){
				if(!g[j]&&b[mi][j]!=0&&d[j]>d[mi]+b[mi][j])d[j]=d[mi]+b[mi][j];
			}
		}
		printf("%d\n",d[y]+u);
	}
	
	return 0;
}