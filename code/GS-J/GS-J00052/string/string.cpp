#include <iostream>
using namespace std;
main (){
	int n=0;
	cin >> n;
	string c[1000];
	for (int i=1;i<=n;i++){
		cin >> c[i];
	}
	
	if(c[1]==c[n] && n%2==1){
		cout << "0";
	}
	return 0;
}
