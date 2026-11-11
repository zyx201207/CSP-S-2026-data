#include<bits/stdc++.h>
using namespace std;
string a, b, c, d;
bool f1, f2, f3, f4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
		f1 = 1;
	}
	else cout << "0";
	
	if (f1 == 0){
		cout << "000";
		return 0;
	}
	
	bool flag = 0;
	for (long long i = 0; i < 2; i++){
		if (b[i] != d[i]){
			flag = 1;
			f2 = 1;
			cout << "0";
			break;
		}
	}
	if (!flag) cout << "1";
	
	if (f2 == 1){
		cout << "00";
		return 0;
	}
	
	if ((d[2] >= 'A' && d[2] <= 'C' && b[2] >= 'A' && b[2] <= 'C') || (d[2] >= 'D' && d[2] <= 'E' && b[2] >= 'D' && b[2] <= 'E')){
		cout << "1";
		f3 = 1;
	}
	else cout << "0";
	
	if (f3 == 0){
		cout << "0";
		return 0;
	}
	
	if (d[2] + 1 == b[2] || d[2] - 1 == b[2]) cout << "1";
	else cout << "0";
	return 0;
}

