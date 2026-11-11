#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1, l1, c2, l2;
	cin >> c1 >> l1 >> c2 >> l2;
	if(c1==c2){
		if(l1[0]==l2[0]&&l1[1]==l2[1]){
			if((l1[2]>='A'&&l2[2]<='C'&&l2[2]>='A'&&l2[2]<='C')||(l1[2]>='D'&&l2[2]<='F'&&l2[2]>='D'&&l2[2]<='F')){
				if((l1[2]=='A'&&l2[2]=='B')||(l1[2]=='B'&&l2[2]=='A')||(l1[2]=='B'&&l2[2]=='C')||(l1[2]=='C'&&l2[2]=='B')||(l1[2]=='D'&&l2[2]=='F')||(l1[2]=='F'&&l2[2]=='D')){
					cout << "1111\n";
				}else{
					cout << "1110\n";
				}
			}else{
				cout << "1100\n";
			}
		}else{
			cout << "1000\n";
		}
	}else{
		cout << "0000\n";
	}
	return 0;
}
