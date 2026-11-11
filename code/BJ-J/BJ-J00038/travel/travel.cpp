#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 == s3){
		cout << '1';
	}else{
		cout << '0';
	}
	if(s1 == s3){
		if(s2[0] == s4[0] && s2[1] == s4[1]){
			cout << '1';
		}else{
		cout << '0';
		}
	}else{
		cout << '0';
	}
	if(s1 == s3){
		if(s2[0] == s4[0] && s2[1] == s4[1]){
			int t1 = -1, t2 = -1;
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
				t1 = 0;
			}else{
				t1 = 1;
			}
			if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C'){
				t2 = 0;
			}else{
				t2 = 1;
			}
			if(t1 == t2){
				cout << '1';
			}else{
				cout << '0';
			}
		}
		else{
			cout << '0';
		}
	}else{
		cout << '0';
	}
	if(s1 == s3){
		if(s2[0] == s4[0] && s2[1] == s4[1]){
			int t1 = -1, t2 = -1;
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
				t1 = 0;
			}else{
				t1 = 1;
			}
			if(s4[2] == 'A' || s4[2] == 'B' || s4[2] == 'C'){
				t2 = 0;
			}else{
				t2 = 1;
			}
			if(t1 == t2){
				char c1 = s2[2], c2 = s4[2];
				if((c1 == 'A' && c2 == 'B') || (c2 == 'A' && c1 == 'B') || (c1 == 'B' && c2 == 'C') || (c2 == 'B' && c1 == 'C') || (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D')){
					cout << '1';
				}else{
					cout << '0';
				}
			}else{
				cout << '0';
			}
		}
		else{
			cout << '0';
		}
	}else{
		cout << '0';
	}
	return 0;
}
