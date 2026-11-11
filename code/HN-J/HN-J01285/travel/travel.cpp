#include <iostream>
using namespace std;

struct player
{
	string a;
	string b;
}m,n;
int xunhuan1()
{
	if(m.b[0]==n.b[0]&&m.b[1]==n.b[1])
	    return 1;
	return 0;
}
int xunhuan2()
{
	if((m.b[2]=='A'||m.b[2]=='B'||m.b[2]=='C')&&(n.b[2]=='A'||n.b[2]=='B'||n.b[2]=='C'))
	    return 1;
	if((m.b[2]=='D'||m.b[2]=='F')&&(n.b[2]=='D'||n.b[2]=='F'))
	    return 1;
	return 0;
}
int xunhuan3()
{
	if((m.b[2]=='A'&&n.a[2]=='B')||(m.b[2]=='B'&&n.b[2]=='C'))
	    return 1;
	if(m.b[2]=='D'&&n.b[2]=='F')
	    return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m.a>>m.b>>n.a>>n.b;
	if(m.a==n.a)
	{
		if(xunhuan1())
		{
			if(xunhuan2())
			{
				if(xunhuan3())
				{
					cout<<"1111";
				}
				cout<<"1110";
			}
			else
			    cout<<"1100";
		}	
		else
		    cout<<"1000";
	}
	else
	    cout<<"0000";
	return 0;
}
