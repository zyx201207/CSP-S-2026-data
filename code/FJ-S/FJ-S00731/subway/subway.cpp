#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin.tie(0);
//	cout.tie(0);
//	ios::sync_with_stdio(0);
	int c,n,m,d,p;
	//c  测试点编号
	//n  地铁线路数
	//m  地铁站数
	//d  每个地铁站最多被几条线路经过
	//p  以及出行计划数
	cin>>c>>n>>m>>d>>p;
	int w[m+10]={};//地铁口->站厅 的时间
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int s[n+10][m+10]={};//地图 线路为行 站数为列
	for(int i=1;i<=n;i++){
		int k;//第 i 条线路经过的站数
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;//经过的地铁站  到该站厅的时间 
			cin>>a>>t;
			s[i][a]=t;//i线路到a站厅的时间
		}
	} 
	for(int i=1;i<=p;i++){//每一个计划 
		int x,y; //起点  终点 
		cin>>x>>y;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<s[i][j]<<"  ";
		}
		cout<<endl;
	} 
	return 0;
}
