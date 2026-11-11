#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2) cout<<"1";
	else cout<<"0";
	if(a1==a2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else cout<<"0";
	if(a1==a2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))) cout<<"1";
	else cout<<"0";
	if(a1==a2&&s1[0]==s2[0]&&s1[1]==s2[1]&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&abs((s1[2]-'0')-(s2[2]-'0'))==1) cout<<"1";
	else cout<<"0";
	return 0;
}
