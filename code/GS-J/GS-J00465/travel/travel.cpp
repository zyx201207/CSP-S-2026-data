#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1[1005],a2[1005];
	for(int i=0;i<2;i++)
	{
		a1[i]=s1[i]-'0';
		a2[i]=s2[i]-'0';
		
	}
	if(c1==c2)
	{
		cout<<1;
		if(a1[1]==a2[1]||a1[2]==a2[2])
		{
			cout<<1;
			if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
			{
				cout<<1<<0;
			}
			else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))
			{
				cout<<1<<1;
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
