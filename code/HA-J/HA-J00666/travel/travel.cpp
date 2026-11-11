#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
}
string c,s,cc,ss;
int fg;
int main()
{
	fre();
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<1;
		fg=1;
	}
	else cout<<0;
	if(fg==0)cout<<0;
	else {
		fg=0;
		if(s[0]==ss[0]&&s[1]==ss[1])
		{
			cout<<1;
			fg=1;
		}
		else cout<<0,fg=0;
	}
	if(fg==0)cout<<0;
	else
	{
		fg=0;
		if(s[2]=='A'&&ss[2]=='B')fg=1;
		if(s[2]=='A'&&ss[2]=='C')fg=1;
		if(s[2]=='B'&&ss[2]=='A')fg=1;
		if(s[2]=='B'&&ss[2]=='C')fg=1;
		if(s[2]=='C'&&ss[2]=='B')fg=1;
		if(s[2]=='C'&&ss[2]=='A')fg=1;
		if(s[2]=='D'&&ss[2]=='F')fg=1;
		if(s[2]=='F'&&ss[2]=='D')fg=1;
		if(fg==1)
		{
			cout<<1;
		}
		else cout<<0,fg=0;
	}
	if(fg==0)
	{
		cout<<0;
	}
	else {
		int flag=0;
		if(s[2]=='A'&&ss[2]=='B')flag=1;
		if(s[2]=='B'&&ss[2]=='A')flag=1;
		if(s[2]=='B'&&ss[2]=='C')flag=1;
		if(s[2]=='C'&&ss[2]=='B')flag=1;
		if(s[2]=='D'&&ss[2]=='F')flag=1;
		if(s[2]=='F'&&ss[2]=='D')flag=1;
		if(flag==1)
		{
			cout<<1;
		}
		else cout<<0;
	}
	return 0;
}
