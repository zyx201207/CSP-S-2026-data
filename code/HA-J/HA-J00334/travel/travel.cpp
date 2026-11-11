#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	s="0000";
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)s="1000";
	else{
		cout << s;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])s="1100";
	else{
		cout << s;
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))s="1110";
	else{
		cout << s;
		return 0;
	}
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)s="1111";
	cout << s;
	return 0;
}
