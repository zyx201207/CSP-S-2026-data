#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans = "0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << ans;
		return 0;
	}
	else{
		ans = "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans += "1";
		}
		else{
			ans += "0";
		}
		if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
			ans += "1";
		}
		else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
			ans += "1";
		}
		else{
			ans += "0";
		}
	}
	char a = s1[2];
	char b = s2[2];
	int c = (int)(a+b);
	if(c == 131 || c == 133 || c == 138){
		ans += "1";
	}
	else{
		ans += "0";
	}
	cout << ans;
	return 0;
}
