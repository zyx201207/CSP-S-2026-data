#include <bits/stdc++.h>
using namespace std;
long long a,c,b,d;
char b1,d1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> b1 >> c >> d >> d1;
	if(a == c) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if(b == d) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	if((b1 >= 'A' && b1 <= 'C' && d1 >= 'A' && d1 <= 'C') || (b1 == 'D' && d1 == 'F') || (b1 == 'F' && d1 == 'D')){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if((b1 == 'A' && d1 == 'B') || (b1 == 'B' && d1 == 'C') || (b1 == 'D' && d1 == 'F') && (b1 == 'B' && d1 == 'A') || (b1 == 'C' && d1 == 'B') || (b1 == 'F' && d1 == 'D')){
		cout << 1;
	}
	else{
		cout << "0";
		return 0;
	}
	return 0;
} 
