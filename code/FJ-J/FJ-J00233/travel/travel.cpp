#include <bits/stdc++.h>
using namespace std;

string cr,sr;
string cx,sx;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> cr >> sr;
	cin >> cx >> sx;
	
	if(cr==cx){
		cout << "1";
		if(sr[0]==sx[0] && sr[1]==sx[1]){
			cout << "1";
			char zr=sr[2],zx=sx[2];
			if('A'<=zr && zr<='C' && 'A'<=zx && zx<='C'){
				cout << "1";
				if(zr=='A' && zx=='C') cout << "0\n";
				else if(zr=='C' && zx=='A') cout << "0\n";
				else cout << "1\n";
			}
			else if('D'<=zr && zr<='F' && 'D'<=zx && zx<='F'){
				cout << "11\n";
			}
			else cout << "00\n";
		}
		else cout << "000\n";
	}
	else cout << "0000\n";
	return 0;
}
