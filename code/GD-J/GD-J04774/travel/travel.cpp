#include<bits/stdc++.h>
using namespace std;
string a1, a2, b1, b2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "t", stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	for(int i = 0; i < a1.size(); i++){
		if(a1[i] != b1[i]){
			cout << "0000";
			return 0;
		}
	}
	for(int i = 0; i < a2.size(); i++){
		if(i == a2.size() - 1){
			int x = a2[i], y = b2[i];
			if(x == 'D' || x == 'F'){
				if(y == 'D' || y == 'F'){
					cout << "1111";
					return 0;
				}
				else {
					cout << "1100";
					return 0;
				}
			}
			if(x == 'A' || x == 'B' || x == 'C'){
				if(y == 'D' || y == 'F') {
					cout <<"1100";
					return 0;
				}
				if(x == 'A' && y == 'C'){
					cout <<"1110";
					return 0;
				}
				if(y == 'A' && x == 'C'){
					cout <<"1110";
					return 0;
				}
				else{
					cout <<"1111";
					return 0;
				}
			}
		}
		else{
			if(a2[i] != b2[i]){
				cout << "1000";
				return 0;
			}
		}
	}
	return 0;
}
