#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(c1 == c2 and (s1[0] == s2[0] and s1[1] == s2[1])){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	int a = s1[2]-'A'+1, b = s2[2]-'A'+1;
	if((c1 == c2 and (s1[0] == s2[0] and s1[1] == s2[1])) and ((a <= 3 and b <= 3) or ( a > 3 and b > 3))){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}
	if((c1 == c2 and (s1[0] == s2[0] and s1[1] == s2[1])) and (a-b == 1 or b-a == 1)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
