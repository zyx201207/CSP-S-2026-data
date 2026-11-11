#include<bits/stdc++.h>
using namespace std;
bool f1, f2, f3;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
		f1 = 1;
	}else{
		cout << 0;
	}
	if(s1[0] == s2[0] && s1[1] == s2[1] && f1){
		cout << 1;
		f2 = 1;
	}else{
		cout << 0;
	}
	if(((s1[2] == 'A' && (s2[2] != 'D' || s2[2] != 'F')) || (s1[2] == 'D' && s2[2] == 'F')) && f1 && f2){
		cout << 1;
		f3 = 1;
	}else if(((s2[2] == 'A' && (s1[2] != 'D' || s1[2] != 'F')) || (s2[2] == 'D' && s1[2] == 'F')) && f1 && f2){
		cout << 1;
		f3 = 1;
	}else{
		cout << 0;
	}
	
	if((s1[2] == 'D' && s2[2] == 'F') && !(s1[2] == 'C' && s2[2] == 'D') && abs(s2[2] - s1[2])== 1 && f1 && f2 && f3){
		cout << 1;
	}else if((s2[2] == 'D' && s1[2] == 'F') && !(s2[2] == 'C' && s1[2] == 'D') && abs(s2[2] - s1[2])== 1 && f1 && f2 && f3){
		cout << 1;
	}else{
		cout << 0;
	}	
	return 0;
}
