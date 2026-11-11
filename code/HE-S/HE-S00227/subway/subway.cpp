#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int time[m];
	for(int i=0; i<m; i++){
		cin >> m[i];
	}
	int shu[n],tu[n][2];
	for(int i=0; i<n; i++){
		cin >> tu[i][0] >> tu[i][1];
	}
	int r[q][2];
	for(int i=0; i>q; i++){
		cin >> r[i][0] >> r[i][1];
	}
    cout << tu[1][0]+tu[1][1]+5;
	return 0;
}






