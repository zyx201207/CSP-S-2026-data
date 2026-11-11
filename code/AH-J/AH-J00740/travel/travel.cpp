#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ll a, b;
	string s1, s2;
	cin >> a >> s1 >> b >> s2;
	string ans;
	
	if(a == b) ans += "1";
	else{ 
		ans += "0000";
		cout << ans;
		return 0;
	}
	
	string x1, x2;
	x1 += s1[0];
	x1 += s1[1];
	x2 += s2[0];
	x2 += s2[1];
	if(x1 == x2) ans += "1";
	else{
		 ans += "000";
		 cout << ans;
		 return 0;
	}
	
	string t1, t2;
	t1 += s1[2];
	t2 += s2[2];
	if((t1 >= "A" && t1 <= "C" && t2 >= "A" && t2 <= "C") || (t1 >= "D" && t1 <= "F" && t2 >= "D" && t2 <= "F")) ans += "1";
	else{
		 ans += "00";
		 cout << ans;
		 return 0;
	}
	
	if((t1 == "A" && t2 == "B") || (t1 == "B" && t2 == "C") || (t1 == "D" && t2 == "E")) ans += "1";
	else{
		ans += "0";
		cout << ans;
		return 0;
	}
	
	cout << ans;
	return 0;
}
