#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> a1 >> b >> b1;
	ll as = a1[2],bs = b1[2];
	if (a == b){
		cout << '1';
		if (a1[0] == b1[0] and a1[1] == b1[1]){
			cout << '1';
			if ((a1[2] >= 'A' and a1[2] <= 'C')and(b1[2] >= 'A' and b1[2] <= 'C')){
				cout << '1';
				if (abs(as - bs) == 1)cout << '1';
				else cout << "0";
				return 0;
			}
			/////////////////
			if ((a1[2] >= 'D' and a1[2] <= 'F')and(b1[2] >= 'D' and b1[2] <= 'F')){
				cout << '1';
				if (abs(as - bs) <= 2)cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		/////////////////////////
		else cout << "000";
	}
	///////////////////////
	else cout << "0000";
	return 0;
}
