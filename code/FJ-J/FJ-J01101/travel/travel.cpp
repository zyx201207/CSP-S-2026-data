#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int a,c;
	string b,d,bb,dd;
	cin>>a>>b>>c>>d;
	bb=b[2];
	dd=d[2];
	if(a==c) 
	{
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1])
		{
			cout<<"1";
			if(bb=="D"||bb=="F")
			{
				if(dd=="D"||dd=="F")
				{
					cout<<"11";
				}
				else cout<<"00";
			}
			else
			{
				if(dd=="A"||dd=="B"||dd=="C")
				{
					cout<<"1";
					if(bb=="B") cout<<"1";
					else if(bb=="A")
					{
						if(dd=="B") cout<<"1";
						else cout<<"0";
					}
					else
					{
						if(dd=="B") cout<<"1";
						else cout<<"0";
					}
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
