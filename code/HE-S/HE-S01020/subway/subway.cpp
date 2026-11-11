#include<bits/stdc++.h>
using namespace std;

const int n_max=500,m_max=5e5;

short c;
int n,m,d;//线路数,站点数,每个地铁站最多过几条线

//所有地铁站/地铁线编号都是从1开始存 
int hall_exit[m_max+5];//站厅-出站口
int hall_stat[m_max+5][n_max+5];//站厅-站台 

vector<int> line[n_max+5];//地铁线路途径站点,下标从0存 

int main(){
	//注释！！！！！！！！！！！！！！！！！！！！！！！！！！！ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>hall_exit[i];
	}
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		while(tmp--){
			int j;
			cin>>j;//地铁站编号
			line[i].push_back(j);
			cin>>hall_stat[j][i]; 
		}
	}
	 
	return 0;
} 
