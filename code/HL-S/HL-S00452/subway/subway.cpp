#include<bits/stdc++.h>
using namespace std;
#define int long long

const int u=1e9+10;
int WAY[u][u];

void ANS(){
	int x,y;
	cin>>x>>y;
	cout<<WAY[x][y];
	return;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++){
			cin>>WAY[i][j];
		}
	}
	for(int k=1;k<=q;k++){
		ANS();
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/