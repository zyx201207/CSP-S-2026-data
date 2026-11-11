//测试样例 2条线路 5个站点 1个站点最多有20条线经过 2个计划 
//i个地铁口到i站厅时间 
//w 1 2 3 4 5
//  4 1 9 2 5
//  
//线路1:(共经过3个站点)
//经过的站点
//a 1 2 3
//  1 2 4
//i线上/下车点到a[i]站点站厅的时间
//t 1 2 3
//  5 7 6 
//  
//线路2:(共经过3个站点)
//经过的站点
//a 1 2 3
//  2 3 5
//i线上/下车点到a[i]站点站厅的时间
//t 1 2 3
//  3 4 7
//  
//出行计划:(共2个) 
//
//计划1:
//从1->3
//先走第一个地铁口到站厅1(w1:4)，从站厅1坐路线1也就是走到路线1的站台(t11:5)
//坐路线1到站台2因为走不动了，从站台2到站厅2(t12:7) ，然后换乘线路2也就是走到线路2的站台(t21:3)
//线路2一直开到终点站台3，从站台3走到站厅3(t22:4)，最后从地铁口3出(w3:9)
//w1+t11+t12+t21+t22+w3=4+5+7+3+4+9=32
//
//
//挖去这诗人啊，理解样例花了我40分钟，气笑了 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005];
long long ans;
bool flagA=true;
void dfs(pair<int,int>q,int mb){//pair:第i个线路经过的第j个站点，即站点a[i][j] 
	int x=q.first,y=q.second;
	ans+=t[x][y];
//	printf("%d\n",a[x][y]);
	if(a[x][y]==mb){
		ans+=w[mb];
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i][1]==a[x][y]){
			ans+=t[i][1];
			dfs({i,2},mb);
			break;
		}
	}
}
void calc(int l,int r){
	for(int i=1;i<=n;i++){
		if(a[i][1]==l){
			ans+=w[l];
			ans+=t[i][1];
			dfs({i,2},r);
			break;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		if(k[i]>2)flagA=false;
		for(int j=1;j<=k[i];j++)scanf("%d%d",&a[i][j],&t[i][j]);
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ans=0;
		calc(l,r);
		printf("%d",ans);
	}
	return 0;
}
/*
0 5 6 99 1
1 2 3 4 5 6
2 1 1 2 1
2 2 1 4 1
2 4 1 3 1
2 3 1 6 1
2 6 1 5 1
1 5


*/
//0 3 4 99 1
//10 10 10 10
//2 1 2 2 3
//2 2 4 3 5
//2 3 6 4 7
//1 4
//算出来47
//入地铁1站厅:10
//入地铁1站1线站台:2
//1线1-2
//入地铁2站厅:3
//入地铁2站2线站台:4
//2线2-3
//入地铁3站站厅:5
//入地铁3站4线站台:6
//入地铁4站站厅:7
//出地铁10
//2+3+4+5+6+7=27
//27+20=47 没有问题 ，我太牛逼 
