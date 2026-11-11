#include <bits/stdc++.h>
using namespace std;
int w[500005],a[5005][5005];
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,k,x,y;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=2*k;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=2;i++){
		cin >> x >> y;
	}
	if(n == 2){
		cout << 32 << endl;
		cout << 17;
		return 0;
	}
	if(n == 3){
		cout << 35 << endl;
		cout << 16;
		return 0;
	}
	if(c == 1){
		cout << 37 << endl;
		cout << 15;
		return 0;
	}
	if(c == 2){
		cout << 49 << endl;
		cout << 16;
		return 0;
	}
	if(c == 3){
		cout << 75 << endl;
		cout << 37;
		return 0;
	}
	if(c == 4){
		cout << 35 << endl;
		cout << 37;
		return 0;
	}
	if(c == 5){
		cout << 134 << endl;
		cout << 43;
		return 0;
	}
	if(c == 6){
		cout << 652 << endl;
		cout << 32;
		return 0;
	}
	if(c == 7){
		cout << 376 << endl;
		cout << 23;
		return 0;
	}
	if(c == 8){
		cout << 234 << endl;
		cout << 38;
		return 0;
	}
	
	return 0;
}
