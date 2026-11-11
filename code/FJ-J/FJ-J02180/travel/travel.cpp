#include <bits/stdc++.h>
using namespace std;
string s1,s2;
long long a1,a2,c1,c2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1;
	cin>>s1;
	cin>>a2;
	cin>>s2;
	c1=(s1[0]-'0')*10+(s1[1]-'0');
	c2=(s2[0]-'0')*10+(s2[1]-'0');
	if(a1==a2)
	{
		cout<<'1';
		if(c1==c2)
		{
			cout<<'1';
			if((s1[2]<'D' && s2[2]<'D') || (s1[2]>'C' && s1[2]>'C'))
			{
				cout<<'1';
				if(abs(s1[2]-s2[2])==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}