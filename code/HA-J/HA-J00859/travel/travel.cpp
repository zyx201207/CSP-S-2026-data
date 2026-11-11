#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if ((s1[0]-48) * 10 +s1[1]-48 == (s2[0]-48)*10 + s2[1]-48){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}if (!((s1[2] == 'C' && s2[2]== 'D') || (s1[2] == 'D' && s2[2]== 'C'))){
		cout << 1;
	}else{
		cout << "00";
		return 0;
	}if ((s2[2]-64 - (s1[2]-64) == 1 || (s1[2]-64 - (s2[2]-64)) == 1)){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
