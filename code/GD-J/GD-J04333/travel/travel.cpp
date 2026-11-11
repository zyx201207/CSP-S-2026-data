#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1="",s1="",c2="",s2="",a="",b="",c="",d="";
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) a = "1";
	else {
		a="0",b="0",c="0",d="0";
		cout << a << b << c << d << endl;
		return 0;	
	}
	
	if(s1[0] == s2[0] && s1[1] == s2[1]) b = "1";
	else{
		b="0",c="0",d="0";
		cout << a << b << c << d << endl;
		return 0;
	}
	
	if(('A'<=s1[2] && 'C'>=s1[2]) && ('A'<=s2[2] && 'C'>=s2[2])) c = "1";
	else if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')) c = "1";
	else{
		c="0",d="0";
		cout << a << b << c << d << endl;
		return 0;
	}
	
	if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1 || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) d = "1";
	else d = "0";

	cout << a << b << c << d << endl;
	return 0;
}
