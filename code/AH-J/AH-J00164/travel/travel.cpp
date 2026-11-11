#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else
	{
		cout<<1;
		if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"000";
		else
		{
			cout<<1;
			if((s1[2]>'C'&&s2[2]<'D')||(s1[2]<'D'&&s2[2]>'C'))
				cout<<"00";
			else
			{
				cout<<1;
				if(abs(int(s1[2])-int(s2[2]))!=1)
					cout<<0;
				else cout<<1;
			}
		}
	}
	return 0;
}
