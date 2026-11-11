#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int time1[100000],time2[1000][1000],k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> time1[i];
	}
	for (int i = 1;i <= n;i++){
	    cin >> k;
		for (int j = 1;j <= k;j++){
			cin >> time2[i][j];
		} 
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
	}
	return 0;
}
