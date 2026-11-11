#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string rc, rz, xc, xz;
	cin >> rc >> rz >> xc >> xz;
	int f = 0;
	if(rc == xc){
		cout << "1";
		f++;
	}
	else cout << "0";
	if(rz[0] == xz[0] && rz[1] == xz[1] && f == 1){
		cout << "1";
		f++;
	}
	else cout << "0";
	if(rz[0] == xz[0] && rz[1] == xz[1] && f == 2){
		if(rz[2] == 'A' && (xz[2] == 'B' || xz[2] == 'C')){
			cout << "1";
			f++;
		}
		else if(rz[2] == 'B' && (xz[2] == 'A' || xz[2] == 'C')){
			cout << "1";
			f++;
		}
		else if(rz[2] == 'C' && (xz[2] == 'A' || xz[2] == 'B')){
			cout << "1";
			f++;
		}
		else if(rz[2] == 'D' && xz[2] == 'F'){
			cout << "1";
			f++;
		}
		else if(rz[2] == 'F' && xz[2] == 'D'){
			cout << "1";
			f++;
		}
		else cout << "0";
	}else cout << "0";
	//cout << f << "\n";
	if(rz[2] == 'A' && xz[2] == 'B') cout << "1";
	else if(rz[2] == 'B' && (xz[2] == 'A' || xz[2] == 'C')) cout << "1";
	else if(rz[2] == 'C' && xz[2] == 'B') cout << "1";
	else if(rz[2] == 'D' && xz[2] == 'F') cout << "1"; 
	else if(rz[2] == 'F' && xz[2] == 'D') cout << "1";
	else cout << "0";
	return 0;
}
