#include <bits/stdc++.h>
using namespace std;
string s, s1, s2, s3;
int t;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s >> s1 >> s2 >> s3;
	if(s == s2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(s1[0] == s3[0] && s1[1] == s3[1]){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(s1[0] == s3[0] && s1[1] == s3[1]){
		if(s1[2] >= 'A' && s1[2] <= 'C'){
			if(s3[2] >= 'A' && s3[2] <= 'C'){
				cout << 1;
				if(s1[2] + 1 == s3[2] || s3[2] + 1 == s1[2]){
					t = 1;
				}
			}else{
				cout << 0;
			}
		}else{
			if(s3[2] >= 'D' && s3[2] <= 'F'){
				cout << 1;
				if(s1[2] + 2 == s3[2] || s3[2] + 2 == s1[2]){
					t = 1;
				}
			}else{
				cout << 0;
			}
		}
	}else{
		cout << 0;
	}
	if(t == 1){
		cout << 1;
	}else{
		cout << 0;	
	}
	return 0;
}
