#include<bits/stdc++.h>
using namespace std;
int w[5010],way[520],a[5010][5010],t[5010][5010],r[5010][5010];



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		way[i] = k;
		for(int j;j<=k*2;j++){
			cin >> a[i][j] >> t[i][j];
		}
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=way[i];j++){
			for(int k=1;k<=way[i];k++){
				r[j][k] = t[i][j] + t[i][k];
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << r[x][y] + w[x] + w[y] << endl;
	}
	
	return 0;
} 
