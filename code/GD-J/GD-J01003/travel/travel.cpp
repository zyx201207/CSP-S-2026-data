#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int c1,s1,c2,s2,g1,g2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	c1=int(a[0]-'0')*10+int(a[1]-'0');
	c2=int(c[0]-'0')*10+int(c[1]-'0');
	s1=int(b[0]-'0')*10+int(b[1]-'0');
	s2=int(d[0]-'0')*10+int(d[1]-'0');
	g1=int(b[2]-'A')+1;
	g2=int(d[2]-'A')+1;
	if(c1==c2)
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			if(g1<=3&&g2<=3||g1>3&&g2>3)
			{
				cout<<1;
				if(abs(g1-g2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
