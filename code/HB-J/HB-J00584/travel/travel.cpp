#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		if(s1[1]==s2[1])
			if(s1[2]<='C'&&s2[2]<='C')
				if(s1[2]=='B'||s2[2]=='B') cout<<"1111";
				else cout<<"1110";
			else if(s1[2]>'C'&&s2[2]>'C') cout<<"1111";
			else cout<<"1100";
		else cout<<"1000";
	else cout<<"0000";
	return 0;
}
