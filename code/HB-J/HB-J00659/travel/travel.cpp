#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string a1=s1.substr(0,2),a2=s2.substr(0,2);
	char b1=s1[2],b2=s2[2];
	if(c1==c2)
	{
		cout<<1;
		if(a1==a2)
		{
			cout<<1;
			if(b1>='D'&&b2>='D') cout<<1<<1;
			else if(b1<='C'&&b2<='C')
			{
				cout<<1;
				if(abs(b1-b2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
