#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		if(b.substr(0,2)==d.substr(0,2))
		{
			cout<<1;
			if((b[2]<'D' && d[2]<'D') || (b[2]>'D' && d[2]>'D'))
			{
				cout<<1;
				if((char(int(b[2])-1)==d[2]) || (char(int(b[2])+1)==d[2]))
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				cout<<"00";
				return 0;
			}
		}
		else
		{
			cout<<"000";
			return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
