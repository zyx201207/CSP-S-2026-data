#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6;
int c,n,m,dd,q,w[maxn],d[5005][5005];
int fir[maxn],nxt[maxn],to[maxn],val[maxn],tot;
struct node{
	int x,d;
	bool operator<(const node a)const{
		return a.d<d;
	}
};
void add(int x,int y,int z){
	nxt[++tot]=fir[x];fir[x]=tot;to[tot]=y;val[tot]=z;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(d,0x3f,sizeof(d));
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			d[i+m][x]=y;
			d[x][i+m]=y;
		}
	}
	for(int i=1;i<=m+n;i++) d[i][i]=0;
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=i;j<=m+n;j++){
				if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[j][i]=d[i][k]+d[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int a=w[x]+w[y]+d[x][y];
		printf("%d\n",a);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
