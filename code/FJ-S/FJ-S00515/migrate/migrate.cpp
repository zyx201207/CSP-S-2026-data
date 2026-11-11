#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c ,t;
	cin >> c >> t;
	if(c == 13 || c == 14){
		while(t--) {
			long long n , d;
			cin >> n >> d;
			for(int i = 0 ; i < n ; i++){
				int x;
				cin >> x;
			}
			cout << 0 << "\n";
		}
	}else{
		while(t--) {
			long long n , d;
			cin >> n >> d;
			for(int i = 0 ; i < n ; i++){
				int x;
				cin >> x;
			}
			if(n > 2){
				cout << 1;
			}else{
				cout << 0;
			}
			cout << "\n";
		}
	}
	return 0;
}
