//GZ-J00119 ∏ﬂŒ≈¥Ô
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string sf,c1,s1,c2,s2;
	cin >> c1 >>s1 >> c2 >> s2;
	if(c1 == c2){
		if(s1[0]==s2[0] && s1[1] == s2[1]){
			if(s1[2] == 'A'&&s2[2] == 'B'){
				sf = "1111";
			}
			else if(s1[2] == 'B'&&s2[2] == 'A'){
				sf = "1111";
			}
			else if(s1[2] == 'C'&&s2[2] == 'B'){
				sf = "1111";
			}
			else if(s1[2] == 'B'&&s2[2] == 'C'){
				sf = "1111";
			}
			else if(s1[2] == 'D'&&s2[2] == 'F'){
				sf = "1111";
			}
			else if(s1[2] == 'F'&&s2[2] == 'D'){
				sf = "1111";
			}
			else if(s1[2] == 'A'&&s2[2] == 'C'){
				sf = "1110";
			}
			else if(s1[2] == 'C'&&s2[2] == 'A'){
				sf = "1110";
			}
			else{
				sf = "1100";
			}
		}
		else{
			sf = "1000"
		}
	else{
		sf = "0000";
	}
	cout << sf;
}
