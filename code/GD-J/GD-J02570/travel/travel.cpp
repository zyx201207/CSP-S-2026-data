#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string ans="";
	if(a[0]==c[0]&&a[1]==c[1])
	{
		ans+="1";
		if(b[0]=d[0]&&b[1]==d[1])
		{
			ans+="1";
			if(b[2]<='C'&&d[2]<='C')
			{
				ans+="1";
			}
			else if(b[2]>'C'&&d[2]>'C')
			{
				ans+="1";
			}
			else
			{
				ans+="00";
			}
		}
		else
		{
			ans+="000";
		}
	}
	else
	{
		ans+="0000";
	}
	int x=max(b[2]-'A',d[2]-'A');
	int y=min(b[2]-'A',d[2]-'A');
	if(ans[2]=='1')
	{
		if(x-y==1)
		ans+="1";
		else
		ans+="0";
	}
	cout<<ans;
	return 0;
}
