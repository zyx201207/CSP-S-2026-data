#include <iostream>
using namespace std;
main(){
	int m=0,n=0;
	cin >> n >> m;
	string a[100];
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	cout << n << " " << m << " " << a[1];
	return 0;
}
