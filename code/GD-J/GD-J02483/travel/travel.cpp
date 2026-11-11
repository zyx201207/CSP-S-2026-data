#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s, r;
	long long s1, r1;
	cin >> s1 >> s >> r1 >> r;
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
	
	if(s1 == r1){
		flag1 = 1;
		if(s[0] == r[0] && s[1] == r[1]){
			flag2 = 1;
		 	if(s[2] >= 'A'&&s[2] <= 'C'&& r[2] >= 'A' && r[2] <= 'C'|| s[2] >= 'D'&&s[2] <= 'F'&& r[2] >= 'D' && r[2] <= 'F' ){
		 		flag3 = 1;
		 		if(s[2] == 'B' || r[2] == 'B' || s[2] == 'D' || s[2] == 'E') flag4 = 1;
			 }
		}
	}
	cout << flag1 << flag2 << flag3 << flag4;
	
	
	return 0;
}
