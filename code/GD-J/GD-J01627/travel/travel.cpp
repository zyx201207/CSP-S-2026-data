#include <bits/stdc++.h>
using namespace std;
string a1, b1, a2, b2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a1 >> b1 >> a2 >> b2;
	if(a1==a2){
		cout << 1;
		if(b1[0]==b2[0] && b1[1]==b2[1]){
			cout << 1;
			if(b1[2]<='C' && b2[2]<='C'){
				cout << 1;
				if(abs(b1[2]-b2[2])==1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else if(b1[2]>='D' && b2[2]>='D'){
				cout << 1 << 1;
			}
			else{
				cout << 0 << 0;
			}
		}
		else{
			cout << 0 << 0 << 0;
		}
	}
	else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
} 
