#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1, s2, c1, c2;
	cin >> s1 >> s2 >> c1 >>c2;
	if(s1 != c1){
		cout << "0000";
		return 0;
	}else{
		cout << 1;
		for(int i = 0;i < 2;i++){
			if(s2[i] != c2[i]){
				cout << "000";
				return 0;
			}else{
				break;
			}
		}
		cout << 1;
		if(s2[2] == 'A' || s2[2] == 'B'|| s2[2] == 'C' && c2[2] == 'A' || c2[2] == 'B'|| c2[2] == 'C'){
			cout << '1';
			if(s2[2] + 1 == c2[2] || s2[2] - 1 == c2[2]){
				cout << 1;
			}else {
				cout << 0;
			}
		}else if( s2[2] == 'D' || s2[2] == 'E' &&  c2[2] == 'D'|| c2[2] == 'E'){
			cout << 1;
			if(s2[2] + 1 == c2[2] || s2[2] - 1 == c2[2]){
				cout << 1;
			}else {
				cout << 0;
			}
		}else{
			cout << "00";
		}
	}
	return 0; 
} 
