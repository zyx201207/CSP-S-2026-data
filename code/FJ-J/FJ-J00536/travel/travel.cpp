#include<bits/stdc++.h>
using namespace std;
char z1,z2,h1,h2,h3,z3,z4,h4,h5,h6;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","std");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> z1 >> z2 >> h1 >> h2 >> h3 >> z3 >> z4 >> h4 >> h5 >> h6;
	if(z1==z3 && z2==z4){
		cout << 1;
		if(h1==h4 && h2==h5){
			cout << 1;
			if(((h3=='D' || h3=='F') && (h6=='D' || h6=='F')) || ((h3=='A' || h3=='B' || h3=='C') && (h6=='A' || h6=='B' || h6=='C'))){
				cout << 1;
				if(!((h3=='A' || h3=='C') && (h6=='A' || h6=='C'))){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << 0 << 0;
			}
		}else{
			cout << 0 << 0 << 0;
		}
	}else{
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}
