#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if (s1 == s3){
		cout << 1;
		string a,b;
		a += s2[0];
		a += s2[1];
		b += s4[0];
		b += s4[1];
		if (a == b){
			cout << 1;
			char a,b;
			a = s2[2];
			b = s4[2];
			if ((a <= 'C' && b <= 'C') || (a >= 'D' && a <= 'E' && b >= 'D' && b <= 'E')){
				cout << 1;
				char a,b;
				a = s2[2];
				b = s4[2];
				if (abs(a-b) == 1){
					cout << 1;
				}
				else cout << "0";
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";	
	return 0;
}
