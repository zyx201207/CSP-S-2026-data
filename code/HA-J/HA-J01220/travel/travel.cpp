#include <bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2,ans;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1[0] != c2[0] || c1[1] != c2[1]){
		ans = "0000";
	}
	else{
		ans += "1";
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			ans += "1";		
			switch(s1[2]) {
				case('A'): {
					switch(s2[2]){
						case('B'): {
							ans += "11";
							break;
						}
						case('C'): {
							ans += "10";
							break;
						}
						default: ans += "00";
					}
				}
				case('B'):{
					switch(s2[2]){
						case('A'): {
							ans += "11";
							break;
						}
						case('C'): {
							ans += "11";
							break;
						}
						default: ans += "00";
					}
					break;
				}
				case('C'):{
					switch(s2[2]){
						case('A'): {
							ans += "10";
							break;
						}
						case('B'): {
							ans += "11";
							break;
						}
						default: ans += "00";
					}
					break;
				}
				case('D'):{
					switch(s2[2]){
						case('F'): {
							ans += "11";
							break;
						}
						default: ans += "00";
					}
					break;
				}
				case('F'):{
					switch(s2[2]){
						case('D'): {
							ans += "11";
							break;
						}
						default: ans += "00";
					}
					break;
				}
			}
		}
	
		else{
			ans += "000";
		}
	}
	for (int i = 0 ; i < 4; i++)
		cout << ans[i];
	return 0;
}