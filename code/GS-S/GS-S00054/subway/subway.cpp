#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int walktime[5*10^5+1], groundway[500][5*10^5+1], subway[500][5*10^5+1], ki[5*10^5+1], start[10^5+1], finish[10^5];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>walktime[i];
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		for(int j=1;j<=ki[i];j++){
			cin>>groundway[i][j];
			cin>>subway[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>start[i];
		cin>>finish[i];
	}
	
	return 0;
} 
