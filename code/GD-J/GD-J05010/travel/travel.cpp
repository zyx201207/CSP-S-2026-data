#include<bits/stdc++.h>
using namespace std;

string ac, bc, as, bs;
int a, b;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> ac >> as >> bc >> bs;
//	cout << ac << as << bc << bs << '\n';
	a=as[2]-'A';
	b=bs[2]-'A';
	as.erase(2);
	bs.erase(2);
////	cout << ac << as << bc << bs << '\n';
//	cout << a << ' ' << b << '\n';
	if (ac==bc){
		cout << 1;
		if(as==bs){
			cout << 1;
			if ((a<3 && b<3)||(a>2 && b>2)){
				cout << 1;
				if(abs(a-b)==1)
					cout << 1;
				else 
					cout << "0";
			}
			else 
				cout << "00";
		}
		else
			cout << "000";
	} else  
		cout << "0000";
//	cout << '\n';
//	cout << ac << as << bc << bs << '\n';
	return 0;
}
