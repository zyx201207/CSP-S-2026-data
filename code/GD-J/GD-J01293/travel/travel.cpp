#include<bits/stdc++.h>
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;cin>>a1>>b1>>a2>>b2;
	map<char,int>mp;mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=11,mp['F']=12;
	if(a1[0]==a2[0]&&a1[1]==a2[1])
	{
		cout<<"1";
		if(b1[0]==b2[0]&&b1[1]==b2[1])
		{
			cout<<"1";
			if((b1[2]<='C'&&b2[2]<='C')||(b1[2]>'C'&&b2[2]>'C'))
			{
				cout<<"1";
				if(abs(mp[b1[2]]-mp[b2[2]])==1)
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
