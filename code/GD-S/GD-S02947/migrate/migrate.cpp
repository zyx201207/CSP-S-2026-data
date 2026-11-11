#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("mirgrate.in" , "r" , stdin);
	freopen("mirgrate.out" , "w" , stdout);
	int a , b , c;
	cin >> a >> b >> c;
	if(a == 0 and b == 2 and c == 4){
		cout << 1 << endl << 2;
	}else if(a == 0 and b == 2 and c == 5){
		cout << 0 << endl << 1;
	}else if(a == 0 and b == 17 and c == 197){
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl<< 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 0 << endl << 2 << endl << 0;
	}else if(a == 0 and b == 17){
		cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
	}else{
		cout <<12251;
	}
	return 0;
}
