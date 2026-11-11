#include<bits/stdc++.h>
using namespace std;
int ktt[100005];// 地铁口到站厅需时间 
int ttt[100005];//站厅到站台需时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long int c,n,m,d,q;//分别表示测试点编号、
	// 地铁线路数、地铁站数、
	//  每个地铁站最多被几条线路经过，以及出行计划数
	cin>>c>>n>>m>>d>>q;
	int time,z,k;
	for(int i=1;i<=m;i++){
	    cin>>ktt[i];	
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
		    cin>>z;
			cin>>time;	
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<(y-x)*time<<endl;
	}
	return 0;
} 
