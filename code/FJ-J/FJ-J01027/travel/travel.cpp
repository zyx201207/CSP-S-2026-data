#include<bits/stdc++.h>
using namespace std;
string ax,ay,bx,by;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ay>>bx>>by;
	if(ax!=bx)
	{
		cout<<"0000"<<'\n';
		return 0;
	}
	else
	{
		cout<<"1";
		string a="0000",b="0000";
		for (int i=0;i<=1;++i)
		  a[i]=ay[i];
		for (int i=0;i<=1;++i)
		  b[i]=by[i];
		if(a!=b)
		{
			cout<<"000"<<'\n';
			return 0;
		}
		else
		{
			cout<<"1";
			char x=ay[2],y=by[2];
			if((x<='C'&&y<='C')||(x>='D'&&y>='D'))
			{
				cout<<"1";
				if((y==(char)(x+1))||(x==(char)(y+1))) cout<<"1"<<'\n';
				else
				{
					cout<<"0"<<'\n';
					return 0;
				}
			}
			else
			{
				cout<<"00"<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
