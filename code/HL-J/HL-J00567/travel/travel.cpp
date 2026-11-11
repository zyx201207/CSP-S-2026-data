#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool flag = true;
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	string A = "";
	A+=b[0];
	A+=b[1];
	string B = "";
	B+=d[0];
	B+=d[1];
	bool l1 = false;
	bool l2 = false;
	
	
	if(b[2] == 'F' || b[2] == 'D'){
		l1 = false;
	}else if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
		l1 = true;
	}
	
	if(d[2] == 'F' || d[2] == 'D'){
		l2 = false;
	}else if(b[2] == 'A' || b[2] == 'B' || b[2] == 'C'){
		l2 = true;
	}

	if(a == c){
		cout << "1";
	}else {
		cout << "0000";
		return 0;
		flag = false;
	}
	
	
	if(A == B){
		cout << "1";
	}else {
		cout << "000";
		return 0;
		flag = false;
	}
	
	
	if(l1 == true && l2 == true){
		cout << "1";
		
	}else if(l1 == false && l2 == false){
		cout << "11";
		return 0;
	}else{
		cout << "00";
		return 0;
		flag = false;
	}
	
	
	if(b[2] != 'C' && (b[2]+1) == d[2]){
			cout << "1";
	}else if(b[2] != 'A' && (b[2]-1) == d[2]){
		cout << "1";
	}else {
		cout << "0";
	}
	return 0;
}
////02 01C 02 01D
