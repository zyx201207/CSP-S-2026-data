#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q,a[501][500001],k[501],w[1000000001],t[501][500001],x[100001],y[100001];

int main(){
	
	cin >> c >> n >> m >> d >> q;
	for(int u=1;u<=m;u++){
		cin >> w[u];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][a[i][j]];
		}
	}
	for(int r=1;r<=q;r++){
		cin >> x[r] >> y[r];
	}
	for(int r=1;r<=q;r++){
		int sum=0,o1,o2;
		sum+=w[x[r]]+w[y[r]];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x[r]||a[i][j]==y[r]){
					sum+=t[i][a[i][j]];
				}
			}
		} 
		cout << sum << endl;
	}
	
	return 0;
}
