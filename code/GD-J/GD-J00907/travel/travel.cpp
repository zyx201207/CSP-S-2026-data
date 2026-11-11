#include<bits/stdc++.h>
using namespace std;

int R, X;
string r, x;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> R;
	cin >> r;
	cin >> X;
	cin >> x;
	if(R != X){
		cout << "0000" << endl;
		return 0;
	}
	cout << 1;
	int a = 0, b = 0;
	for(int i = 0; i < 2; i ++){
		a = a * 10 + r[i];
		b = b * 10 + x[i];
	}
	if(a != b){
		cout << "000" << endl;
		return 0;
	}
	cout << 1;
	char n = r[2], m = x[2];
	if(n == 'A' || n == 'B' || n == 'C'){
		if(m == 'D' || m == 'F'){
			cout << "00" << endl;
			return 0;
		}
	}
	else if(n == 'D' || n == 'F'){
		if(m == 'A' || m == 'B' || m == 'C'){
			cout << "00" << endl;
			return 0;
		}
	}
	cout << 1;
	if((n == 'A' && m == 'B') || (m == 'A' && n == 'B') || (n == 'B' && m == 'C') || (n == 'C' && m == 'B') || (n == 'D' && m == 'F') || (n == 'F' && m == 'D')){
		cout << 1 << endl;
	}
	else cout << 0 << endl;
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
