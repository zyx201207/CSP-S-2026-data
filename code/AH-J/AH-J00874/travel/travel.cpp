#include <bits/stdc++.h>
using namespace std;
char a[3]={'A','B','C'};
char b[3]={'D','F'};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>t1>>s2>>t2;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
		if(t1[0]==t2[0]&&t1[1]==t2[1])
		{
			cout<<1;
			int c1,c2;
			for(int i=0;i<3;i++) if(t1[2]==a[i]) c1=1;
			for(int i=0;i<2;i++) if(t1[2]==b[i]) c1=2;
			for(int i=0;i<3;i++) if(t2[2]==a[i]) c2=1;
			for(int i=0;i<2;i++) if(t2[2]==b[i]) c2=2;
			if(c1==c2)
			{
				cout<<1;
				if(c1==2) cout<<1;
				else if(t1[2]=='A'&&t2[2]=='B') cout<<1;
				else if(t1[2]=='B'&&t2[2]=='C') cout<<1;
				else if(t1[2]=='B'&&t2[2]=='A') cout<<1;
				else if(t1[2]=='C'&&t2[2]=='B') cout<<1;
				else
				{
					cout<<0;
					return 0;
				}
			}
			else
			{
				cout<<00;
				return 0;
			}
		}
		else
		{
			cout<<000;
			return 0;
		}
	}
	else
	{
		cout<<0000;
		return 0;
	}
	return 0;
}
