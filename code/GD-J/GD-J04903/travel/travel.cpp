#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out","w",stdout);
	int cc1, cc2;
	string ss1, ss2;
	cin >> cc1 >> ss1 >> cc2 >> ss2;
	string ans = "";
	ans += (cc1 == cc2) ? '1' : '0';
	ans += (ans[0] == '1' && ss1[0] == ss2[0] && ss1[1] == ss2[1]) ? '1' : '0';
	int sd1 = 0, sd2 = 0;
	if(ss1[2] == 'D' || ss1[2] == 'F')sd1 = 1;
	if(ss2[2] == 'D' || ss2[2] == 'F')sd2 = 1;
	ans += (ans[1] == '1' && sd1 == sd2) ? '1' : '0';
	string ch;
	if(ss1[2] == 'A' || ss1[2] == 'C')ch = "BB";
	if(ss1[2] == 'B')ch = "AC";
	if(ss1[2] == 'D')ch = "FF";
	if(ss1[2] == 'F')ch = "DD";
	ans += (ans[2] == '1' && (ss2[2] == ch[0] || ss2[2] == ch[1])) ? '1' : '0';
	cout << ans;
} 
