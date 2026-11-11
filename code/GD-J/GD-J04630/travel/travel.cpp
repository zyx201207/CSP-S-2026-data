#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans;
	if(c1 == c2){
		ans += '1'; 
		if(s1[0] == s2[0] && s2[1] == s1[1]){
			ans += '1';
			if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')){
				ans += '1';
				if((s1[2] == 'A' && s2[2] == 'B') ||(s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
					ans += '1';
				}else{
					ans = "1110";
				}
			}
			else{
				ans ="1100";
			}
		}
		else{
			ans = "1000";
		}
	}
	else{
		ans = "0000";
	}
	cout << ans;
	return 0;
} 
