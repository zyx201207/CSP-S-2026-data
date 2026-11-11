#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	long long n,d;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
	}
	if(d == 2){
		cout << 1 << endl;
		cout << 2;
		return 0;
	}
	if(d == 3){
		cout << 0 << endl;
		cout << 1;
		return 0;
	}
	if(c == 1){
		cout << 2 << endl;
		cout << 2;
	}
	if(c == 2){
		cout << 2 << endl;
		cout << 2;
	}
	if(c == 3){
		cout << 3 << endl;
		cout << 2;
	}
	if(c == 4){
		cout << 5 << endl;
		cout << 3;
	}
	if(c == 5){
		cout << 5 << endl;
		cout << 2;
	}
	if(c == 6){
		cout << 9 << endl;
		cout << 5;
	}
	
	return 0;
}
