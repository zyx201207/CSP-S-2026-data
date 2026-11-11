#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char a[3];
	char b[4];
	char c[3];
	char d[4];
	cin>>a[1]>>a[2];
	cin>>b[1]>>b[2]>>b[3];
	cin>>c[1]>>c[2];
	cin>>d[1]>>d[2]>>d[3];
	bool n=false;//02 02B 02 01A
	if(a[1]==c[1] && a[2]==c[2])//0=0 && 2=2 
	{
		cout<<"1";//100
		if(b[1]==d[1] && b[2]==d[2])//0=0 2!=1
		{
			cout<<"1";
			if((b[3]<='C' && d[3]<='C' )|| (b[3]>'C' && d[3]>'C'))
			{
				cout<<"1";
				n=true;
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"00";
		}
		
	}
	else
	{
		cout<<"000";	
	} 
	if(n==true)//n=false
	{
		if(char(int(b[3])+1)==d[3] || char(int(b[3])-1)==d[3])
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		cout<<"0";//0;
	}//1000
	return 0;
}
