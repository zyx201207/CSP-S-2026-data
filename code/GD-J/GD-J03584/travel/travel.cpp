#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rr,xx;
	string rwei,xwei;
	cin >> rr >> rwei >> xx >> xwei;
	if(rr != xx){
		cout << "0000";
	}
	else{
		cout << '1';
		for(int i = 0;i < 2;i++){
			if(rwei[i] != xwei[i]){
				cout << "000";
				return 0;
			}
		}
		cout << '1';
		if((rwei[2] != 'D' && rwei[2] != 'F') && (xwei[2] != 'D' && xwei[2] != 'F')){
			cout << '1';
			if(abs((int)(rwei[2] - xwei[2])) == 1) cout << '1';
			else cout << '0';
		}
		else if((rwei[2] == 'D' || rwei[2] == 'F') && (xwei[2] == 'D' || xwei[2] == 'F')){
			cout << '1';
			if(abs((int)(rwei[2] - xwei[2])) == 1) cout << '1';
			else cout << '0';
		}
		else cout << "00";
	}
	return 0;
} 
