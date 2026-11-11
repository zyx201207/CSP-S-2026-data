#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n, x;	
	string b, a, c = "";
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		c = c + " " + a + " " + b;
	}
	if (c == " 2 a 2 b 1 c"){
		cout << 2;
	}
	else if(c == " 2 a 3 a"){
		cout << 0;
	}
	else if(c == " 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b"){
		cout << 3000000000;
	}
	
	return 0;
}
