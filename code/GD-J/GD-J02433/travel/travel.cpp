#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>s;
	if (a != b) cout<<"0000";
	else if (stoi(c.substr(0,2)) != stoi(s.substr(0,2))) cout<<"1000";
	else{
		if ((c[2] == 'F' || c[2] == 'D') && (s[2] == 'F' || s[2] == 'D')) cout<<"1111";
		else if ((c[2] == 'A' || c[2] == 'B' || c[2] == 'C') && (s[2] == 'A' || s[2] == 'B' || s[2] == 'C')){
			if (c[2] == 'B' || s[2] == 'B') cout<<"1111";
			else cout<<"1110";
		} 
		else cout<<"1100";
	}
	return 0;
} 
