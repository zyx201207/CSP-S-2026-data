#include <bits/stdc++.h>
#define int long long 

using namespace std;

int x[4];
string c1, s1, c2, s2;

signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int ans = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] != c2[0] || c1[1] != c2[1]){
		x[0] = 0;
	} else {
		x[0] = 1;
	}
	if(x[0] == 0){
		x[1] = 0;
	} else {
		if(s1[0] != s2[0] || s1[1] != s2[1]) {
			x[1] = 0;
		} else {
			x[1] = 1;
		}
	}
	if(x[1] == 0){
		x[2] == 0;
	} else {
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')){
				x[2] = 0;
			
			} else {
				x[2] = 1;
			}
		} else {
			x[2] = 0;
		}
	}
	if(s1[0] == s2[0] && s1[1] == s2[1]){
		if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1){
			if((s1[2] != 'C' && s2[2] != 'D') || (s1[2] != 'D' && s1[2] != 'C')){
				x[3] = 1;
			}
		} else {
			x[3] = 0;
		}
	} else {
		x[3] = 0;
	}
	for(int i = 0; i < 4; i++){
		cout << x[i]; 
	}
	return 0;
} 
