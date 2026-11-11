#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool book[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		int f=0,fl=0;
		book[1]=1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			f=1;
			book[2]=1;
		}	
		if(f==1&&((b[2]>='A'&&d[2]>='A'&&b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')))
		{
			fl=1;
			book[3]=1;
		}
		if(f==1&&fl==1&&(char(b[2]+1)==d[2]||char(b[2]-1)==d[2]))
		{
			book[4]=1;
		}
		else if(f==1&&fl==1&&((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')))
		{
			book[4]=1;
		}
	}
	for(int i=1;i<=4;i++)cout<<book[i];
	return 0;
}
