#include<bits/stdc++.h>
using namespace std;
string a1 , a2 , b1 , b2;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	int ll = 1;
	for(int i = 0  ; i < 2 ; i ++){
		if(a1[i] != b1[i]){
			ll = 0;
			break;
		}
	}
	cout << ll;
	
	if(ll == 1){
		for(int i = 0 ; i < 2 ; i ++){
			if(a2[i] != b2[i]){
				ll = 0;
				break;
			}
		}
		cout << ll;
		if(ll == 1){
			if(a2[2] == 'A' && b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')cout << 1;
			else if(a2[2] == 'B' && b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')cout << 1;
			else if(a2[2] == 'C' && b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')cout << 1;
			else if(a2[2] == 'D' && b2[2] == 'D' || b2[2] == 'E')cout << 1;
			else if(a2[2] == 'E' && b2[2] == 'D' || b2[2] == 'E')cout << 1;
			else {
				cout << 0;
				ll = 0;
			}
		}
		else cout << 0;
		if(ll == 1){
			if(a2[2] == 'A' && b2[2] == 'B' || a2[2] == 'B' && b2[2] == 'A')cout<< 1;
			else if(a2[2] == 'B' && b2[2] == 'C' || a2[2] == 'C' && b2[2] == 'B')cout << 1;
			else if(a2[2] == 'C' && b2[2] == 'D' || a2[2] == 'D' && b2[2] == 'C')cout << 1;
			else if(a2[2] == 'D' && b2[2] == 'E' || a2[2] == 'E' && b2[2] == 'D')cout << 1;
			else cout << 0 ;
		}
		else cout << 0;
	}
	else cout << "000";
	
	return 0;
}
