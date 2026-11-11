#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r",stdin);
	freopen("travel.out", "w",stdout);
	string c1,c2,c3,c4;
	cin >> c1 >> c2 >> c3 >> c4;
  	int n1 = c2[0] + c2[1];
	int n2 = c4[0] + c4[1];
   	int z1 = c2[2];
	int z2 = c4[2];
	if (c1 == c3){
		cout << 1;
		if(n1 == n2){
			cout << 1;
			if((z1 == 'A' || z1 == 'B' || z1 == 'C') && (z2 == 'A' || z2 == 'B' || z2 == 'C')){
				cout << 1;
				if(z1 == 'B' || z2 == 'B'){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else if((z1 == 'D' || z1 == 'F') && (z2 == 'D' || z2 == 'F')){
				cout << 1;
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else{
			cout << 0;
		}	
	}
	else{
		cout << 0;
	}
	return 0; 
}