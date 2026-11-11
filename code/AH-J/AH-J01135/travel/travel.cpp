#include <bits/stdc++.h>
using namespace std;
bool ce(string a,string b)
{
	if(a[2]=='A')
	{
		if(b[2]=='B')
		{
			return 1;
		}
	} else if(a[2]=='B'){
		if(b[2]=='A'||b[2]=='C')
		{
			return 1;
		}
	} else if(a[2]=='C'){
		if(b[2]=='B')
		{
			return 1;
		}
	} else if(a[2]=='D'){
		if(b[2]=='F')
		{
			return 1;
		}
	} else {
		if(b[2]=='D')
		{
			return 1;
		}
	}
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<1;
			if(b[2]>='A'&&b[2]<='C')
			{
				if(d[2]>='A'&&d[2]<='C')
				{
					cout<<1;
					if(ce(b,d)==1)
					{
						cout<<1;
					} else {
						cout<<0;
					}
				} else {
					cout<<"00";
				}
			} else if(b[2]>='D'&&b[2]<='F'){
				if(d[2]>='D'&&d[2]<='F')
				{
					cout<<1;
					if(ce(b,d)==1)
					{
						cout<<1;
					} else {
						cout<<0;
					}
				}else {
					cout<<"00";
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
