#include<bits/stdc++.h>
using namespace std;
int a, b, d, e;
char c, f;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d >> e >> f;
	if(a == d){
		cout << 1;
		if(b == e){
			cout << 1;
			if((c == 'A'||c == 'B'||c == 'C'&&f == 'A'||f == 'B'||f == 'C')||(c == 'D'||c == 'F'&&f == 'D'||f == 'F')){
				cout << 1;
				if((c == 'A'&&f == 'B')||(c == 'B'&&f == 'A')||(c == 'B'&&f == 'C')||(c == 'C'&&f == 'B')||(c =='D'&&f == 'F')||(c == 'F'&&f == 'D')){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
