#include<bits/stdc++.h>
using namespace std;

string op1, n, op2, m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> op1 >> n >> op2 >> m;
	if(op1 == op2){
		cout << 1;
		if(n[0] == m[0] && n[1] == m[1]){
			cout << 1;
			if((n[2] <= 'C' && m[2] <= 'C') || (n[2] >= 'D' && m[2] >= 'D')){
				cout << 1;
				if(n[2] - m[2] == 1 || n[2] - m[2] == -1){
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
