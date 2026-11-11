#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long s11,s22;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[2]=='A') s11=1;
	if(s1[2]=='B') s11=2;
	if(s1[2]=='C') s11=3;
	if(s1[2]=='D') s11=4;
	if(s1[2]=='F') s11=5;
	if(s2[2]=='A') s22=1;
	if(s2[2]=='B') s22=2;
	if(s2[2]=='C') s22=3;
	if(s2[2]=='D') s22=4;
	if(s2[2]=='F') s22=5;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		if((s11<=3&&s22<=3)||(s11>3&&s22>3))
		{
			cout<<1;
			if((s11<3&&s22<3)||(s11>3&&s22>3)||(s11>1&&s22>1&&s11<4&&s22<4)) cout<<1;
			else cout<<"0";
		}
		else cout<<"00"; 
	}
	else cout<<"000";
	return 0;
} 
