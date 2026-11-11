#include<bits/stdc++.h>
using namespace std;
struct subway {
	
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int 
	c,//测试 
	n,//地铁线数 
	m,//地铁站数 
	d,//每个地铁站最多被几条线路经过
	q;//出行计划数
	cin >> c >> n >> m >> d >> q;
	int w[m];//每个地铁站的地铁口走到站厅需要的时间
	for(int i=0;i<m;i++){
		cin >> w[i];
	}
	int at[m][d*2+1];
	for(int i=0;i<m;i++){
		cin >> at[i][0];
		for(int j=0;j<at[i][0]+1;k++){
			cin >> at[i][j+1]
		}
	}
	int ql[q][2];
	for(int i=0;i<q;i++){
		cin >> q[i][0] >> q[i][1];
	}
	
	
	for(int q1=0;q1<q1++){
		int ans=0;
		
		
		//
		
		
		cout << ans << endl;
	}
	
	return 0;
}
