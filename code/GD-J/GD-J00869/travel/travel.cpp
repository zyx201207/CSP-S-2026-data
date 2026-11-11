#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a,b,x,y;
	cin >> a>> b>> x>> y;	
	if (a == x){
		cout << "1";
		if (b[0] == y[0]){
			if (b[1] == y[1]){
				cout << "1";
				if ((char(b[2]) <= 67 && char(y[2]) <= 67) || (char(b[2]) >= 68 && char(y[2]) >= 68)){
					cout << 1;
					if (char(b[2]) + 1 == char(y[2]) || char(b[2]) - 1 == char(y[2])){
						cout << 1;
					}else{
						cout << "0";
					}
				}else{
					cout << "00";
					return 0;
				}
			}else{
				cout << "000";
				return 0;
			}
		}else{
			cout << "000";
			return 0;
		}
	}else{
		cout << "0000";
		return 0;
	}
}
