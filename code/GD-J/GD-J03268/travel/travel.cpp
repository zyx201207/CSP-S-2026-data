#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c, s, c1, s1;
	cin >> c >> s >> c1 >> s1;
	string p1, p2, q1, q2;
	p1 = s[0]+s[1];
	p2 = s1[0]+s1[1];
	q1 = s[2];
	q2 = s1[2];
	string ans = "";
	if(c == c1){
		ans += '1';
		if(p1 == p2){
			ans += '1';
			if((q1 == "F" || q1 == "D") && (q2 == "F" || q2 == "D") || ((q1 == "A" || q1 == "B" || q1 == "C") && (q2 == "A" || q2 == "B"  || q2 == "C"))){
				ans += '1';
				if(((q1 == "F" || q1 == "D") && (q2 == "F" || q2 == "D")) || ((q1 == "A" || q1 == "B") && (q2 == "A" || q2 == "B")) || ((q1 == "C" || q1 == "B") && (q2 == "C" || q2 == "B"))){
					ans += '1';
				}else{
					ans += "0";
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
