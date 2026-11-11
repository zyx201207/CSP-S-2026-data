#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int f=0,a=0,b=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){cout<<'1';a=1;}
	else cout<<'0';
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&a==1){cout<<'1';b=1;}
	else cout<<'0';
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&b==1){cout<<'1';f=1;}
	else cout<<'0';
	if(abs(s1[2]-s2[2])==1&&f==1)cout<<'1';
	else cout<<'0';
	return 0;
}
