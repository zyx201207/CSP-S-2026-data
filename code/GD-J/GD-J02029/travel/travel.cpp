#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1])
	{
		cout<<1;
		char a=s1[2],b=s2[2];
		if(a=='A' and b=='B') cout<<"11";
		else if(a=='A' and b=='C') cout<<"10";
		else if(a=='A') cout<<"00";
		else if(a=='B' and b=='A') cout<<"11";
		else if(a=='B' and b=='C') cout<<"11";
		else if(a=='B') cout<<"00";
		else if(a=='C' and b=='B') cout<<"11";
		else if(a=='C' and b=='A') cout<<"10";
		else if(a=='C') cout<<"00";
		else if(a=='D' and b=='F') cout<<"11";
		else if(a=='D') cout<<"00";
		else if(a=='F' and b=='D') cout<<"11";
		else cout<<"00";
	}
	else
	{
		cout<<"000";
	}
}
