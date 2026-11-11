#include<bits/stdc++.h>
using namespace std;
int ax,bx,az,bz;
char aZ,bZ;
char c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ax >> c;
	az = int(c - '0') * 10;
	cin >> c;
	az += int(c - '0');
	cin >> aZ;
	
	cin >> bx >> c;
	bz = int(c - '0') * 10;
	cin >> c;
	bz += int(c - '0');
	cin >> bZ;
	
	if(ax == bx){
		cout << 1;
		if(az == bz){
			cout << 1;
			if(((aZ == 'A' || aZ == 'B' || aZ == 'C') && (bZ == 'A' || bZ == 'B' || bZ == 'C')) || ((aZ == 'D' || aZ == 'E') && (bZ == 'D' || bZ == 'E'))){
				cout << 1;
				if(aZ == 'A' && bZ == 'B'){
					cout << 1;
				}
				else if(aZ == 'B' && (bZ == 'A' || bZ == 'C')){
					cout << 1;
				}
				else if(aZ == 'C' && bZ == 'B'){
					cout << 1;
				}
				else if(aZ == 'D' && bZ == 'E'){
					cout << 1;
				}
				else if(aZ == 'E' && bZ == 'D'){
					cout << 1;
				}
				else{
					cout << 0;
					return 0;
				}
			}
			else{
				cout << "00";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
	}
	else{
		cout << "0000";
		return 0;
	}
	return 0;
}