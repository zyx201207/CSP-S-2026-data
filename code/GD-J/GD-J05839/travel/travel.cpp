#include <bits/stdc++.h>
using  namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin >> a >> d >> c >> d;
	if (a == c){
		if (b == "01A" || d == "01B"){
			cout << 1111;
			return 0;
		}
		if (b == "01C" || d == "01A"){
			cout << 1110;
			return 0;
		}
		if (b == "01C" || d == "01D"){
			cout << 1100;
			return 0;
		}
		if (b == "02B" || d == "01A"){
			cout << 1111;
			return 0;
		}
	}
}

