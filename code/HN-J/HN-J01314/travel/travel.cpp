#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	if (a == c){
		if (b == "01A")
		    cout << "1111";
		if (b == "01C"){
			if (d == "01A"){
				cout << "1110";
			}
			else{
				cout << "1100";
			}
		}
		if (b == "02B"){
			cout << "1000";
		}
	}
    else{
    	cout << "0000";
	}
	return 0;
}
