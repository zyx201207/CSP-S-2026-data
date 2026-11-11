//GZ-J00151 安顺市实验学校 罗子骏
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,h1,h2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	} 
	
	bool f=1;
	h1=s1[0]+s1[1];
	h2=s2[0]+s2[1];
	
	if(h1==h2) cout<<'1';
	else{
		cout<<"000";
		return 0;
	} 
	if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s2[2]-'A'>=3))
	{
		cout<<'1';
	}
	else cout<<'0';
	
	if(((s1[2]-s2[2]==1&&(s1[2]!='D'&&s1[2]!='C'))||(s1[2]-s2[2]==-1&&(s1[2]!='C'&&s1[2]!='D'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))) cout<<'1';
	else cout<<'0';
	
	return 0;
} 
