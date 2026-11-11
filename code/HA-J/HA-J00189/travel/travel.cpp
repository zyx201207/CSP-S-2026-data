#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[0]='1';
	else {
		ans="0000";
		cout<<ans;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]) ans[1]='1';
	else {
		ans="1000";
		cout<<ans;
		return 0;
	}
	if(abs(s1[2]-s2[2])==2 && (s1[2]=='A' || s2[2]=='A') || abs(s1[2]-s2[2])==1 && (s1[2]!='C' && s2[2]!='D') && (s1[2]!='D' && s2[2]!='C') || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D') ans[2]='1';
	else {
		ans="1100";
		cout<<ans;
		return 0;
	}
	if(abs(s1[2]-s2[2])==1 || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D') ans[3]='1';
	else {
		ans="1110";
		cout<<ans;
		return 0;
	}
	cout<<ans;
	return 0;
}
