#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,ss,tt;
	cin>>s>>t>>ss>>tt;
	if(s==ss)
	{
		cout<<'1';
		if(t[0]==tt[0]&&t[1]==tt[1])
		{
			cout<<'1';
			char a=t[2],b=tt[2];
			if((a=='D'&&b=='F')||(a=='F'&&b=='D')) cout<<"11";
			else if((a=='A'&&b=='B')||(a=='B'&&b=='A')) cout<<"11";
			else if((a=='B'&&b=='C')||a=='C'&&b=='B') cout<<"11";
			else if((a=='A'&&b=='C')||(a=='C'&&b=='A')) cout<<"10";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
