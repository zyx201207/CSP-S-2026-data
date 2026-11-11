#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;			//c是测试点的编号 n是地铁线路数 m是地铁站数 d是每个地铁站最多被几条线路经过 q是出行计划数
const int W=5e5+5;
long long x[10005],y[10005];
long long w[10005];					//w[i] 	 	表示从第i个地铁站的地铁口走到站厅需要的时间	 往返是一样的
long long k[505];				//k[i]      表示第 i 条线路经过的地铁站数
int a[505][W],t[505][W];	//a[i][j]   表示第 i 条线路经过的第 j 个地铁站	t[i][j] 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		if(n==1){
			cout<<w[x[i]]+w[y[i]]+t[1][x[i]]+t[1][y[i]]<<"\n";
		}
	}
	return 0;
}
