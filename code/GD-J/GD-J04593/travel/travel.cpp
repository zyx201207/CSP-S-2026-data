#include<bits/stdc++.h>
using namespace std;
char c[10],s[10],cc[10],ss[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c[0]!=cc[0]||c[1]!=cc[1])
	{
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(!(s[0]==ss[0]&&s[1]==ss[1]))
	{
		cout<<"000";
		return 0;
	}
	cout<<'1';
	if(!((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D')))
	{
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if(abs(s[2]-ss[2])==1) cout<<'1';
	else cout<<'0';
	return 0;
}
