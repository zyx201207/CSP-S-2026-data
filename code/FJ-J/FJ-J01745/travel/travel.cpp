#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c1,c2,d1,d2;
	char c3,d3;
	cin>>c1>>c2>>d1>>d2;
	c3=c2[2],d3=d2[2],s=c2[0],s+=c2[1],c2=s,s=d2[0],s+=d2[1],d2=s;
	if(c1==d1)
	{
		cout<<1;
		if(c2==d2)
		{
			cout<<1;
			if(c3<='C'&&d3<='C'||'C'<c3&&'C'<d3)
			{
				cout<<1;
				if(c3=='A'&&d3=='C'||c3=='C'&&d3=='A')
					cout<<0;
				else
					cout<<1;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
