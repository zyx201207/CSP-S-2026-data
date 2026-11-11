#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("train.in","r",stdin);
	freopen("train.out","w",stdout);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	char g = b[2];
	char h = d[2];
	if(a==c) {
		if (((g == 'A' && h == 'C') || (g == 'C' && h == 'A'))&& ((b[0] == d[0]) && (b[1] == d[1]))) cout << 1110;
		else if (((g == 'A' && h == 'B') || (g == 'B' && h == 'A') || (g == 'B' && h =='C') || (g == 'C' && h == 'B') || (g == 'D' && h == 'F') || (g == 'F' && h == 'D'))&& ((b[0] == d[0]) && (b[1] == d[1]))) cout << 1111;
		else if(((b[0] == d[0]) && (b[1] == d[1]))) cout << 1100;
		else cout << 1000;
	}
	else cout << 0000;
	return 0;
}
 
