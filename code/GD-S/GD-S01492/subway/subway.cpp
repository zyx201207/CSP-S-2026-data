#include<bits/stdc++.h>
using namespace std;
const int mM=(1+500)*500/2;
int c,n,m,d,q,w[mM],a[501][mM],t[501][mM],k;
//w1, w2, . . . , wm，依次表示从每个地铁站的地铁口走到站厅需要的时间。
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	// c, n, m, d, q分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++){
		scanf("%d",w[i]);
	}for(int i=1;i<=n;i++){
		//第一个正整数为 ki，表示第 i 条线路经过的地铁站数
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[i][j],&t[i][j]);
		}
		//ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间。
	}//floyd
	for(int i=1;i<=n;i++){//中转 
		for(int j=1;j<=n;j++){//起点 
			for(int k=1;k<=n;k++){//终点 
				if(j==k) {
					
				}
			} 
		} 
	}
	while(q--){
		scanf("%d%d",X,Y);	
	}
	
	return 0;
}

