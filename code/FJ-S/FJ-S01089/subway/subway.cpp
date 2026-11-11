#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long sum=0;
long long w[125255],k[505],a[505][1015],t[505][1015],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
	for(int i=1;i<=m;i++) cin>>w[i];//从每个地铁站的地铁口走到站厅需要的时间。
	for(int i=1;i<=n;i++){
		cin>>k[i];//第i条线路经过的地铁站数
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//a 表示第 i 条线路经过的第j 个地铁站
								//t 表示从该地铁站的站厅走到第i条线路的站台需要的时间。
		}
	}
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>x[i]>>y[i];//第r 个出行计划的起点和终点所在的地铁站编号。
		sum+=w[x[i]]+w[2*y[i]];
//		for(int l=1;l<y[i];l++){
//			for(int j=1;j<y[i];j++){
//				sum+=t[l][j];
//			}
//		}
		sum+=t[x[i]][y[i]];
		sum+=t[y[i]-x[i]][x[i]];
		cout<<sum<<endl;
	}
	return 0;
}
//
// 0 3 7 20 2 8 3 6 1 7 2 9 3 1 4 2 5 5 100 3 2 6 3 1 7 2 4 3 2 5 100 4 6 6 7 1 6 2 3
