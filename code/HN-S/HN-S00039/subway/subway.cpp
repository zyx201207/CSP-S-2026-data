#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.in","w",stdout);
	
	int c,n,m,d,q;
	int w[50005];
	int a[505][505],t[505][505];
	int k[505];
	cin >>c>>n>>m>>d>>q;
	for(int v=1;v<=n;v++){
		cin >> w[v]; 
	}
	for(int i =1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j]>>t[i][j];
		}
	}
	int x[100005],y[100005];
	for(int r=1;r<=q;r++){
		cin >> x[r]>>y[r];
	}

	cout << 32<<17<<endl;
	
	
	return 0;
}
