#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int x,y;
char m,n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=10*(b[0]-'0')+b[1]-'0';
	y=10*(d[0]-'0')+d[1]-'0';
	m=b[2];
	n=d[2];
	cout<<x<<" "<<y<<endl;
	cout<<m<<" "<<n<<endl;
	if(a==c)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if(x==y)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if(x==y&&(((m=='A'||m=='B'||m=='C')&&(n=='A'||n=='B'||n=='C'))||((m=='D'||m=='F')&&(n=='D'||n=='F'))))
	{
		ans+='1';
	}
	else
	{
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	if(abs(m-n)<=1&&!((m=='D'&&n=='C')||(m=='C'&&n=='D')))
	{
		ans+='1';
	}
	else ans+='0';
	cout<<ans;
	return 0;
}
