#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	int m,n;
	cin>>m>>a>>n>>b;
	if(m==n)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	int t=a[2],r=b[2];
	if(t=='A'||t=='B'||t=='C')
	{
		if(r=='A'||r=='B'||t=='C')
		cout<<"1";
	}
	else if(t=='D'||t=='E')
	{
		if(r=='D'||r=='F')
		{
			cout<<"1";
		}
	}
	else if(r=='C'&&t=='D'||r=='D'&&t=='C')
	{
		cout<<"00";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(t-r==1||r-t==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
