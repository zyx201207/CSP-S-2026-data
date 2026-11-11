#include<bits/stdc++.h>
using namespace std;
struct Subway{
	long long k;//该地铁经过的地铁站数 
}subway[505];
struct Station{
	long long a;//表示第 i 条线路经过的第 j 个地铁站
	long long t;//从该地铁站的站厅走到第 i 条线路的站台需要的时间。
}station[500005];
long long c,n,m,d,q;
//c 测试点
//n 地铁线路数
//m 地铁站数
//d 每个地铁站最多被几条线路经过
//q 出行计划数
long long w[500005];//地铁口到站厅的时间  
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) {
		cin>>w[i];
	} 
	for(long long i=1;i<=n;i++) {
		cin>>subway[i].k;
		for(long long j=1;j<=subway[i].k;j++) {
			cin>>station[j].a>>station[j].t;
		}
	}
	for(long long i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		int total=w[x]+w[y];
		for(int j=1;j<=n;j++) {
			if (subway[j].k>total) {
				total=subway[j].k;
			}
		}
		cout<<total;
	}
	return 0;
}
