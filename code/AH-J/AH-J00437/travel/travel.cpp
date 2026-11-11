#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll xa , xb;
string s1 , s2 , ans;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> xa >> s1 >> xb >> s2;
	if(xa == xb){
		ans += '1';
		ll a = s1[0] * 10 + s1[1];
		ll b = s2[0] * 10 + s2[1];
		if(a == b){
			ans += '1';
			char c1 = s1[2] , c2 = s2[2];
			if((c1 >= 'D' && c2 >= 'D') || (c1 <= 'C' && c2 <= 'C')){
				ans += '1';
				if((c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D') || (abs(c1 - c2) == 1 && c1 != 'D' && c2 != 'D')) ans += '1';
				else ans += '0';
			} else ans += "00";
		} else ans += "000";
	} else ans = "0000";
	cout << ans;
	return 0;
}// forAC solve100p
