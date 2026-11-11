#include<bits/stdc++.h>
using namespace std;
char c,a,b;
int a1 = 0,a2 = 0,b1 = 0,b2 = 0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2;
	cin >> a;
	cin >> b1 >> b2;
	cin >> b;
	if(a1 == b1) cout << 1;
	else{
		cout << "0000" << endl;
		return 0;
	}
	
	if(a2 == b2) cout << 1;
	else{
		cout << "000" << endl;
		return 0;
	}
	
	if((a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D')) cout << 1;
	else{
		cout << "00" << endl;
		return 0;
	}
	
	if((((a - 'A') - (b - 'A')) == 1) || (((a - 'A') - (b - 'A')) == -1) || (a == 'D' && b == 'F') || (a == 'F' && b == 'D')) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
