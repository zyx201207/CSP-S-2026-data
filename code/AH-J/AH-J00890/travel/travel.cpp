#include<bits/stdc++.h>
using namespace std;
char a[5], b[5], x[5], y[5];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>> x[0]>> x[1]>> y[0]>> y[1]>> y[2]>> a[0]>> a[1]>> b[0]>> b[1]>> b[2];
	if(x[0] == a[0] && x[1] == a[1]){
		cout<< "1";
		if(y[0] == b[0] && y[1] == b[1]){
			cout<< "1";
			int f = 0;
			if(y[2] == 'A'){
				if(b[2] == 'B' || b[2] == 'C'){
					cout<< "1";f = 1;
				}else cout<< "00";
			}else if(y[2] == 'B'){
				if(b[2] == 'A' || b[2] == 'C'){
					cout<< "1";f = 1;
				}else cout<< "00";
			}else if(y[2] == 'C'){
				if(b[2] == 'A' || b[2] == 'B'){
					cout<< "1";f = 1;
				}else cout<< "00";
			}else if(y[2] == 'D'){
				if(b[2] == 'F'){
					cout<< "1";f = 1;
				}else cout<< "00";
			}else{
				if(b[2] == 'D'){
					cout<< "1";f = 1;
				}else cout<< "00";
			}
			if(f == 1){
				if(y[2] == 'A' && b[2] == 'B'){
					cout<< "1";
				}else if(y[2] == 'B' && (b[2] == 'A' || b[2] == 'C')){
					cout<< "1";
				}else if(y[2] == 'C' && b[2] == 'B'){
					cout<< "1"; 
				}else if(y[2] == 'D' && b[2] == 'F'){
					cout<< "1";
				}else if(y[2] == 'F' && b[2] == 'D'){
					cout<< "1";
				}else{
					cout<< "0";
				}
			}
		}else{
			cout<< "000";
		}
	}else{
		cout<< "0000";
	}
	return 0;
}
