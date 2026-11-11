#include<bits/stdc++.h>

using namespace std;

int c1, c2, f1, f2, f3, f4;
string s1, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		f1 = 1;
	} else{
		cout << 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && f1){
		cout << 1;
		f2 = 1;
		if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
			cout << 1;
			f3 = 1;
		} else if((s1[2] == 'D' || s1[2] == 'E') && (s2[2] == 'D' || s2[2] == 'E')){
			cout << 1;
			f3 = 1;
		} else{
			cout << 0;
	    }
	} else{
		cout << 0 << 0;
	}
	if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2]){
		if(!f1 || !f3){
			cout << 0;
		} else{
			cout << 1;
			f4 = 1;
		}
	} else{
		cout << 0;
	}
	return 0; 
}
/*
Trick||Treat!
*/
