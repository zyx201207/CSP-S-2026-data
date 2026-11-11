#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	
	cin>>c1>>s1>>c2>>s2;
	int r1,r2;
	int pd1;
	r1=(s1[0]-'0')*10+(s1[1]-'0');
	r2=(s2[0]-'0')*10+(s2[1]-'0');
	if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C')&&(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'))pd1=1;
	else if((s1[2]=='D' || s1[2]=='F')&&(s2[2]=='D' || s2[2]=='F'))pd1=2;
	else pd1=0;
	
	if(c1==c2)
	{
		cout<<"1";
		if(r1==r2)
		{
			cout<<"1";
			if(pd1==1)
			{
				cout<<"1";
				if(abs(s1[2]-s2[2])==1) {cout<<"1";}
				else {cout<<"1";}
			}
			else if(pd1==2) cout<<"11";	
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}