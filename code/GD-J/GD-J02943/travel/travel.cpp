#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)ans+="1";
	else ans+="0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))ans+="1";
	else ans+="0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&
	((s1[2]<='C'&&s2[2]<='C')||
	(s1[2]>='D'&&s2[2] >= 'D')))ans+="1";
	else ans+="0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&
	((s1[2]<='C'&&s2[2]<='C')||
	(s1[2]>='D'&&s2[2] >= 'D'))&&(s1[2]-s2[2] == 1||s1[2]-s2[2] == -1))ans+="1";
	else ans+="0";
	cout << ans;
	return 0;
}
