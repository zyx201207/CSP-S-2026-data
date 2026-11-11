#include<bits/stdc++.h>
using namespace std;
int main(){
	string a, b, c, d;
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	cin >> a >> c >> b >> d;
    int _a, _b;
    _a = a[0] - '0' * 10 + a[1] - '0';
    _b = b[0] - '0' * 10 + b[1] - '0';
    if(_a == _b){
    	cout << 1;
    	if(c[0] == d[0] && c[1] == d[1]){
    		cout << 1;
    		if(c[2] > 'C' && d[2] > 'C' || c[2] < 'D' && d[2] < 'D'){
    			cout << 1;
    			if(abs(c[2] - d[2]) == 1)cout << 1;
    			else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
} 
