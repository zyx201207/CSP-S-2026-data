#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string c, d;
	cin >> a >> c >> b >> d;
	if (a == b){
		cout << 1;
		if (c[0] == d[0] && c[1] == d[1]){
			cout << 1;
			if (((c[2] == 65 || c[2] == 66 || c[2] == 67) && (d[2] == 65 || d[2] == 66 || d[2] == 67)) || ((c[2] == 68 || c[2] == 69) && (d[2] == 68 || d[2] == 69))){
				cout << 1;  
				if (c[2] + 1 == d[2] ||c[2] - 1 == d[2]){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0 << 0;
			}	
		}else{
			cout << 0 << 0 << 0;  
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
