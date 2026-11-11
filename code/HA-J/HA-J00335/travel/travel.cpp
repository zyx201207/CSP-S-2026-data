#include <bits/stdc++.h>
using namespace std;
 
string c1, s1, c2, s2;
bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		f1 = 1;
	} else{
		f1 = 0;
	}
	//
	if (s1[0] == s2[0] && s1[1] == s2[1] && f1){
		f2 = 1;
	} else{
		f2 = 0;
	}
	//
	if (((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) && f2 && f1){
		f3 = 1;
	} else{
		f3 = 0;
	}
	//
	if (s1[2] > s2[2]){
		if (s1[2] - s2[2] == 1 && s1[2] != 'D' && s2[2] != 'C' && f3 && f2 && f1){
			f4 = 1;
		} else{
			f4 = 0;
		}
	} else{
		if (s2[2] - s1[2] == 1 && s2[2] != 'D' && s1[2] != 'C' && f3 && f2 && f1){
			f4 = 1;
		} else{
			f4 = 0;
		}
	}
	//
	if (f1) cout << 1;
		else cout << 0;
	if (f2) cout << 1;
		else cout << 0;
	if (f3) cout << 1;
		else cout << 0;
	if (f4) cout << 1;
		else cout << 0;
	return 0;
}