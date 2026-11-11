#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","w",in);
	freopen("travel.out","r",out)
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans+='1';
	else {
		ans+='0';
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])ans+='1';
	else {
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||
		'D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')ans+='1';
	else {
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if(s1[2]-1==s2[2]||s1[2]+1==s2[2])ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}
