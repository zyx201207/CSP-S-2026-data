#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 5 , M = 1e5 + 5;
int c,n; //地铁线路数
int m; //地铁站数
int d; //每个地铁站最多被几条线路经过
int q; //出行计划数
int w[N]; //每个地铁站的地铁口走到站厅需要的时间
int k[N]; //表示第 i 条线路经过的地铁站数
int a[500][M]; //a[i][j] 表示第 i 条线路经过的第 j 个地铁站
int t[500][M]; //该地铁站的站厅走到第 i 条线路的站台需要的时间
int xx[M],yy[M]; //第 r 个出行计划的起点和终点所在的地铁站编号
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]；
			cin>>t[i][a[i][j]];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xx[i]>>yy[i];
		if(n==1) cout<<w[xx[i]]+w[yy[i]]+t[1][xx[i]]+t[1][yy[i]]<<endl;
		
	}
	if(c>=16&&c<=19) 
	return 0;
}
/*
0 1 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
1 3
1 2
*/
