#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,t,t1;
	cin>>s>>s1>>t>>t1;
	if(s==t)
	{
		cout<<"1";
		if(s1[0]==t1[0]&&s1[1]==t1[1])
		{
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&t1[2]>='A'&&t1[2]<='C')
			{
				cout<<"1";
				if(abs(s1[2]-t1[2])==1) cout<<"1";
				else cout<<"0";
			}
			else if(s1[2]>='D'&&s1[2]<='F'&&t1[2]>='D'&&t1[2]<='F')
				cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
