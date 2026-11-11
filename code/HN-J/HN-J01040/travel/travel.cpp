#include<bits/stdc++.h>

using namespace std;
using ll = long long;

string c1, c2, s1, s2, ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){ // 同一车厢 
		ans += '1';
		if(s1[0] == s2[0] && s1[1] == s2[1]){ //  同一排 
			ans += '1';
			if( (s1[2] == 'A' && ( (s2[2] == 'B') || (s2[2] == 'C') ) ) || (s1[2] == 'B' && ( (s2[2] == 'A') || (s2[2] == 'C') ) ) || (s1[2] == 'C' && ( (s2[2] == 'A') || (s2[2] == 'B') ) ) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') ){ // 同一侧 
				ans += '1'; 
				if( (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') ){ // 相邻					
					ans += '1'; 
				}else{
					ans += '0';
				}
			}else{
				ans += "00";
			}
		}else{
			ans += "000"; 
		}
	}else{
		ans += "0000";
	}
	cout << ans;
	return 0;
} 
