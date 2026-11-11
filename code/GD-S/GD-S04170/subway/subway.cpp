#include <bits/stdc++.h>
using namespace std;
int w[10000];
int le[10000][500][2];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			cin >> le[j][i][0] >> le[j][i][0];
		}
	}
	
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		int time = w[x] + w[y];
		
	}
	return 0;
} 
