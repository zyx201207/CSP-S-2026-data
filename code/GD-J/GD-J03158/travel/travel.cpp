#include <bits/stdc++.h>
using namespace std; 
string c1,s1,c2,s2;
string ans;
bool pd2(char a,char b)
{
	if((a == 'F' && b == 'D') || (a == 'D' && b == 'F') || (a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'B' && b == 'A') || (a == 'C' && b == 'B')){
		return 1;
	}
	return 0;
}
bool pd1(char a,char b){
	if((a == 'F' && b == 'D') || (a == 'D' && b == 'F') || (a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'B' && b == 'A') || (a == 'C' && b == 'B') || (a == 'C' && b == 'A') || (a == 'A' && b == 'C')){
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)
	{
		bool flag = 0;
		ans += '1';
		string s = s1.substr(0,2);
		string ss = s2.substr(0,2);
		if(s == ss){
			ans += '1';
			flag = 1;
		} else{
			ans +="0";
		}
		bool flag1 = 0;
		if(flag && pd1(s1[2],s2[2])){
			ans += '1';
			flag1 = 1;
		} else{
			ans += "0";
		}
		if(flag1 && pd2(s1[2],s2[2])){
			ans += '1';
		} else{
			ans +='0';
		}
	}else{
		ans = "0000";
	}
	cout << ans;
	return 0;
}
