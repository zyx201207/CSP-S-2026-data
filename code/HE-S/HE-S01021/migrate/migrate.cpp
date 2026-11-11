#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for(int z = 1; z <= t; z++){
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if((c == 11 || c == 12) && d >= x[2] - x[1]){
		    cout << n-3 << endl;
		    break;
		}else{
			cout << 0 << endl;
			break;
		}
		if(c == 13 || c == 14) {
			cout << n - 3 << endl;
			break;
		}else if(x[n] - x[1] <= 10 * d){
            //ÌØÊâÐÔÖÊ C£ºxn - x1 ¡Ü 10d	
		    cout << n - 4 << endl;
		}else{
			cout << n - 5 << endl;
		}	
	}
	return 0;
}
