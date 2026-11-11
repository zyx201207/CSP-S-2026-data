#include <bits/stdc++.h>
using namespace std;
bool check(char c,char d){
	if (c == 'A' && (d == 'B' || d == 'C')) return true;
	else if (d == 'A' && (c == 'B' || c == 'C')) return true;
	else if (c == 'D' && d == 'F') return true;
	else if (c == 'F' && d == 'D') return true;
	return false;
}
bool check2(char c,char d){
	if (abs((int)c - (int)d) == 1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car1,car2,sit1,sit2;
	cin >> car1 >> sit1 >> car2 >> sit2;
	string ans;
	if (car1 == car2) ans+='1';//判断同车厢 
	else{
		ans += "0000";
		cout << ans << '\n';
		return 0; 
	}
	if (sit1[0] == sit2[0] && sit1[1] == sit2[1]) ans+='1';//判断同排 
	else{
		ans += "000";
		cout << ans << '\n';
		return 0;
	}
	char c_1 = sit1[2];
	char c_2 = sit2[2];
	bool flag = true;
	if (check(c_1,c_2)) ans+='1';//判断同过道 
	else{
		ans += "00";
		cout << ans << '\n';
		return 0;
	}
	if (check2(c_1,c_2)) ans+='1';//判断相邻 
	else ans += '0';
	cout << ans;
	return 0;
}
