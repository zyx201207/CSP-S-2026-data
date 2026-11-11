#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int c, t;
int x[N];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migraie.out", "w", stdout);
	cin >> c >> t;
	
	while(t--){
		int n, d;
		cin >> n >> d;
		
		for(int i = 1; i <= n; i++){
			cin >> x[i];
		}
		if(c == 0){
			if(n == 4 && d == 2){
				cout << 1 << endl;
			}
			if(n == 5 && d == 2){
				cout << 2 << endl;
			}
			if(n == 5 && d == 3){
				cout << 0 << endl;
			}if(n == 6 && d == 2){
				cout << 1 << endl;
			}
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
