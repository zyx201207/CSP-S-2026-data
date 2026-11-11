#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool check1(){
	char x = c2[2],y = s2[2];
	if(x == 'A' && (y == 'B' || y == 'C')) return true;
	if(x == 'B' && (y == 'A' || y == 'C')) return true;
	if(x == 'C' && (y == 'A' || y == 'B')) return true;
	if(x == 'D' && y == 'F') return true;
	if(x == 'F' && y == 'D') return true;
	return false;
}
bool check2(){
	char x = c2[2],y = s2[2];
	if(x == 'A' && y == 'B') return true;
	if(x == 'B' && (y == 'A' || y == 'C')) return true;
	if(x == 'C' && y == 'B') return true;
	if(x == 'D' && y == 'F') return true;
	if(x == 'F' && y == 'D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);/////////////////////////////////////////////若要测试，请务必注释freopen 
	freopen("travel.out","w",stdout);///////////////////////////////////////////测试结束，请务必打开freopen
	cin >> c1 >> c2 >> s1 >> s2;
	string ans;
	if(c1 != s1){
		ans = "0000";
	}
	else{
		ans += "1";
		if(c2[0] == s2[0] && c2[1] == s2[1]){
			ans += "1";
			if(check1()){
				ans += "1";
				if(check2()){
					ans += "1";
				}
				else ans += "0";
			}
			else ans += "00";
		}
		else ans += "000";
	}
	cout << ans;
	return 0;
}
