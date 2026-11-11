#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	
	int a[m+5];
	for(int i=1;i<=m;i++) cin >>a[i];//地铁口到站台的时间 
	
	while(q--){
		int zhanshu;//站数 
		cin >> zhanshu;
		int zhanyushi[zhanshu][2];//经过的站口和站厅到站台所需时间 
		for(int i=0;i<zhanshu;i++) for(int j=0;j<2;j++) cin >> zhanyushi[i][j];
	}
	
	
	
	return 0;
} 
