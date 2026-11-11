#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	int a[1001];
	cin >> c >> t >> n >> d ;
	if ((d-1)%n==0){
		cout <<2;
	}else if ((n-1)%d!=0){
		cout << (n-1)/d;
	}
	
	return 0;
}
