#include <bits/stdc++.h>
using namespace std;
struct seat{//×ùÎ»ºÅ 
	string n;//ÅÅ 
	char l;//ABCDF
}r1,x1;
struct w{
	string a;//³µÏá 
	seat b;//×ùÎ»ºÅ 
}r,x;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string S,T;
	cin >> S;
	r.a = S;
	cin >> T;
	for (int i = 0; i <= T.length(); i++){
		if (T[i]>='0'&&T[i]<='9') r1.n+=T[i];
		else r1.l+=T[i];
	}
	r.b = r1;
	cin >> S;
	x.a = S;
	cin >> T;
	for (int i = 0; i <= T.length(); i++){
		if (T[i]>='0'&&T[i]<='9') x1.n+=T[i];
		else x1.l+=T[i];
	}
	x.b = x1;
	if (r.a!=x.a){
		cout << "0000";
		return 0;
	}
	else{
		cout << 1;
		if (r1.n==x1.n){
			cout << 1;
			if ((r1.l<='C')==(x1.l<='C')){
				cout << 1;
				if (abs(r1.l-x1.l)==1){
					cout << 1;
					return 0;
				}
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
