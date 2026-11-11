#include <bits/stdc++.h>

using namespace std;

bool check2(string c,string d){
	if(c[2] == d[2] + 1 || c[2] == d[2] - 1) return true;
	else return false;
}
bool check(string a,string b){
	if((a[2] >= 65 && a[2] <= 67) && (b[2] >= 65 && b[2] <= 67)) return true;
	else if((a[2] >= 68 && a[2] <= 70) && (b[2] >= 68 && b[2] <= 70)) return true;
	else return false;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1,s1,c2,s2,ans;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans += "1";
	}
	else ans += "0";
	if((s1[0] + s1[1]) == (s2[0] + s2[1])){
		ans += "1";
	}
	else ans += "0";
	if((s1[0] + s1[1]) == (s2[0] + s2[1]) && check(s1,s2)){
		ans += "1";
	}
	else ans += "0";
	if((s1[0] + s1[1]) == (s2[0] + s2[1]) && check(s1,s2) && check2(s1,s2)){
		ans += "1";
	}
	else ans += "0";
	cout << ans << endl;
	return 0;
}
