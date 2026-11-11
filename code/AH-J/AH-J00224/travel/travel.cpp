#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (a==c){
		cout << "1";
	}
	else {
		cout << "0000";
		return 0;
	}
	for (int i=0;i<2;i++){
		if (b[i]!=d[i]){
			cout << "000";
			return 0;
		}
	}
	cout << "1";
	if ((b[2]=='F'&&d[2]=='D')||(b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='C')){
		cout << "11";
	}
	else if ((d[2]=='F'&&b[2]=='D')||(d[2]=='A'&&b[2]=='B')||(d[2]=='B'&&b[2]=='C')){
		cout << "11";
	}
	else if ((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A')){
		cout << "10";
	}
	else cout << "00";
	return 0;
}