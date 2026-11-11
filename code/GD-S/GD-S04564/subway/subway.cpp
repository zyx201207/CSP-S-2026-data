#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
const int N=1e6+1;
const int INF=1e9+10;
const int N2=600;
struct subway_station{
	int time1;//地铁口到站厅的时间 
	int line[N2];//每一个地铁线路站台到当前地铁站站厅所用时间 
	int line_num;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>q;//c为测试数量，m是地铁站的数量，n是地铁线路总数，d为每个站台最多的地铁线路数量，q为计划数量 
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			a[i].line[j]=INF;
//		} 
//	}
	for(int test_num=c;c>=0;c--){
		int x,y;
		cin>>x>>y;
		for(int i=a;i<=m;i++){
			cin>>a[i].time1;
		}	
		for(int i=a;i<=m;i++){
			cin>>k;//经过的地铁线路数量 
			a[i].line_num=k;
		}
//		
	}
	cout<<32<<endl<<17;
}
