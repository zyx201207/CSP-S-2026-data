#include<bits/stdc++.h>
using namespace std;
char c1[10],c2[10],s1[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1+1>>s1+1>>c2+1>>s2+1;
	if(c1[1]==c2[1] && c1[2]==c2[2])
	{
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1] && s1[2]==s2[2])
	{
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[3]=='A' && s2[3]=='B') || (s1[3]=='A' && s2[3]=='C') || (s1[3]=='B' && s2[3]=='C') || (s1[3]=='B' && s2[3]=='A') || (s1[3]=='C' && s2[3]=='A') || (s1[3]=='C' && s2[3]=='B') || (s1[3]=='D' && s2[3]=='E') || (s1[3]=='E' && s2[3]=='D'))
	{
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((s1[3]=='A' && s2[3]=='B') || (s1[3]=='B' && s2[3]=='A') || (s1[3]=='B' && s2[3]=='C') || (s1[3]=='C' && s2[3]=='B') || (s1[3]=='D' && s2[3]=='E') || (s1[3]=='E' && s2[3]=='D'))
	{
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
