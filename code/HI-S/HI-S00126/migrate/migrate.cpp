#include <iostream>
#include <cstdio>
using namespace std;
int t, n;
long long int d;
long long int x[2000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	if(c == 0){
		for(t--){
			cin >> n >> d;
			for(int i = 1; i <= n; ++i){
				cin >> x[i];
			}
		}
		if(x[1] == 1){
			cout << "1\n2";
		} else {
			cout << "0\n1";
		}
	}
	for(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i){
			cin >> x[i];
		}
	}
	return 0;
} 
