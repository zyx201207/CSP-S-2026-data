#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	int a, b;
	char a1[7];
	char b1[7];
	cin >> a;
	for (int i = 0; i <= 2; i++){
		cin >> a1[i];
		
	}
	cin >> b;
	for (int i = 0; i <= 2; i++){
		cin >> b1[i];
	}
	if (a == b){
		cout << '1';
	}
	else{
		cout << '0' << '0' << '0' <<'0';
		return 0;
	}
	if (a1[0] == b1[0] and a1[1] == b1[1]){
		cout << '1';
	}
	else{
		cout << '0' <<'0' << '0';
		return 0;
	}
	if ((a1[2] == 'A' or a1[2] == 'B' or a1[2] == 'C' )and (b1[2] == 'A' or b1[2] == 'B' or b1[2] == 'C' )){
			cout << '1';
	}
	else if ((a1[2] == 'F' or a1[2] == 'D')and (b1[2] == 'F' or b1[2] == 'D')){
			cout << '1';
	}
	else if (a1[2] == 'C' and b1[2] == 'D'){
		cout << '0'<<'0';
		return 0;
	}
	else{
		cout << '0' << '0';
		return 0;
	}
	if (a1[0] == b1[0] and a1[1] == b1[1]) {
		if (a1[2] == 'A' and b1[2] == 'B'){
			cout << '1';
		}
		else if (a1[2] == 'B' and b1[2] == 'A'){
			cout << '1';
		}
		else if (a1[2] == 'B' and b1[2] == 'C'){
			cout << '1';
		}
		else if (a1[2] == 'C' and b1[2] == 'B'){
			cout << '1';
		}		
		else if (a1[2] == 'F' and b1[2] == 'D'){
			cout << '1';
		}
		else if (a1[2] == 'D' and b1[2] == 'F'){
			cout << '1';
		}
		else{
			cout << '0';
			return 0;
		}
	}
	return 0;
}
