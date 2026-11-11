#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	for (long long i = 1 ; i <= t; i++){
		long long n,d,x,y;
		cin >> n >> d >> x >> y;
		for (long long i = 3; i <= n ;i++){
			long long x;
			cin >> x;
		}
		cout << n - (d/(y-x)+1)<< "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
