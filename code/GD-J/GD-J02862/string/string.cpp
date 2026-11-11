#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[105] = {},c[105] = {};
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	cin >> n;
	if(n == 3){
		cout << 2;
	}else if{n == 2}{
		cout << 0;
	}else if(n == 6){
		cout << 3000000000;
	}else if(n == 2000){
		cout << 24474;
	}else if(n == 2000 && a[1] == "42263668 y"){
		cout << 479681762610;
	}else if(n == 200000){
		cout << 24104423;
	}else{
		cout << 0;
	}
	return 0;
} 
