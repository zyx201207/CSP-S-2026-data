#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)cout<<1;
	else cout<<0;
	if (c1==c2&&s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else cout<<0;
	if (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')))cout<<1;
	else cout<<0;
	if (c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&((abs(s1[2]-s2[2])==1)||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
	else cout<<0;
	return 0;
}
