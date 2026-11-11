#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q,w[500010],a[2010][2010],v[500010],d[500010],sz[500010];
void dij(){
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	for(int i=1;i<m;i++){
		int x=0;
		for(int j=1;j<=m;j++){
			if(v[j]==0&&(x==0||d[x]>d[j])){
				x=j;
			}
		}
		v[x]=1;
		for(int y=1;y<=m;y++){
			d[y]=min(d[y],d[x]+a[x][y]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++){
		int k,sum=0;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,z;
			scanf("%d%d",&x,&z);
			if(i==x){
				sum=z;
				continue;
			}
			a[i][x]=min(a[i][x],sum+z);
			a[x][i]=a[i][x];
		}
	}
	dij();
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=q;i++){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		printf("%d\n",w[xx]+w[yy]+abs(d[yy]-d[xx]));
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
