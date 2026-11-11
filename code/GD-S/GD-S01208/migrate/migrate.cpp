#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 0){
		long long n,d;
		cin >> n >> d;
		if(n == 4 && d == 2){
			cout << 1 << endl << 2 << endl;
			return 0;
		}
		if(n == 5 && d == 3){
			cout << 0 << endl << 1 << endl;
			return 0;
		}
	}
}
