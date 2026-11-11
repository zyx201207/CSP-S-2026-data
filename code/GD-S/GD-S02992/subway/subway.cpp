#include<bits/stdc++.h>
using namespace std;
const int M=2e4+10;
int c,n,m,d,q,w[M],ki,ai,u,v;
int t[M][510];//存储每个站点代表的向量 
int f[1010][1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(t,0x3f,sizeof t);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++){
			scanf("%d",&ai);
			scanf("%d",&t[ai][i]);
		}
	}
	if(c>=1&&c<=11){
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				int mi=0x3f3f3f3f;
				for(int k=1;k<=n;k++){
					int sum=0x3f3f3f3f;
					if(t[i][k]!=0x3f3f3f3f&&t[j][k]!=0x3f3f3f3f){
						sum=t[i][k]+t[j][k];
					}
					mi=min(mi,sum);
				}
				if(mi!=0x3f3f3f3f) f[i][j]=f[j][i]=mi;
			}
		}
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(f[i][k]!=0x3f3f3f3f&&f[k][j]!=0x3f3f3f3f){
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					}
				}
			}
		}//floyd
		while(q--){
			scanf("%d%d",&u,&v);
			printf("%d\n",f[u][v]+w[u]+w[v]);
		}
	}
	return 0;
}
/*
如何储存分层图 xxx
一种O(d*m^2)的存图方法 
一个站点有d个从站台走到站厅的时间 用向量存储 
站点i与站点j 的向量相加，选出最小的分量作为边长
如果边长是inf，则不连通
用floyd找最短路 1~8点都可以用这个办法 
1 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 pass

1 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3 pass

大样例 4~6 pass 
大样例 9~11 pass 

特判1 如果数据不极端的话可以有40分 

12~15
*/
