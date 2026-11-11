#include<bits/stdc++.h>
using namespace std;
string c,cc;
char s[50],ss[50];
bool d=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1])
	{
		cout<<1;
		d=1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((s[2]<'D'&&ss[2]<'D')||(s[2]>='D'&&ss[2]>='D'))
	{
		cout<<1;
	}
	else 
	{
		cout<<"00";
		return 0;
	}
	if(abs(s[2]-ss[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
