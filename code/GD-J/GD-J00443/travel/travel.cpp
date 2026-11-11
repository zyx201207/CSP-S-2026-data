#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int c1_,c2_,s1_,s2_;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	c1_ = 10*(int)(c1[0]-'0') + (c1[1]-'0');
	c2_ = 10*(int)(c2[0]-'0') + (c2[1]-'0');
	if(c1_ != c2_){
		cout << "0000";
		return 0;
	}
	
	s1_ = 10*(int)(s1[0]-'0') + (s1[1]-'0');
	s2_ = 10*(int)(s2[0]-'0') + (s2[1]-'0');
	if(s1_ != s2_){
		cout << "1000";
		return 0;
	}
	
	bool flag2 = ((s1[2] == 'A') or (s1[2] == 'B') or (s1[2] == 'C'));
	bool flag3 = ((s2[2] == 'A') or (s2[2] == 'B') or (s2[2] == 'C'));
	
	bool flag4 = ((s1[2] == 'D') or (s1[2] == 'F'));
	bool flag5 = ((s2[2] == 'D') or (s2[2] == 'F'));
	
	if((flag2 && flag5) || (flag4 && flag3)){
		cout << "1100";
		return 0;
	}
	
	bool flag6 = (s1[2] == 'A' && s2[2] == 'B');
	bool flag7 = (s1[2] == 'B' && s2[2] == 'A');
	bool flag8 = (s1[2] == 'B' && s2[2] == 'C');
	bool flag9 = (s1[2] == 'C' && s2[2] == 'B');
	bool flag10 = (s1[2] == 'D' && s2[2] == 'F');
	bool flag11 = (s1[2] == 'F' && s2[2] == 'D');
	if(flag6 || flag7 || flag8 || flag9 || flag10 || flag11){
		cout << "1111";
		return 0;
	}else{
		cout << "1110";
		return 0;
	}
	return 0; 
}
