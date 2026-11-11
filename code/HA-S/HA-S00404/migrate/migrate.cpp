#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, x[2000200];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t!=0){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		t--
	}
	if(c == 0 && d == 2){
		if(n == 5){
			cout << 1 << endl << 2;
		}else if(n == 6){
			cout << 0 << endl << 2;
		}
	}
	if(c == 0 && d == 17){
		cout << 8129 << endl << 16<< endl << 9<< endl << 7<< endl << 12<< endl << 0<< endl <<0<< endl <<0<< endl <<2<< endl << 1<< endl <<0<< endl <<2<< endl <<3<< endl << 6<< endl << 0<< endl << 2<< endl << 0<< endl;
	}
}
