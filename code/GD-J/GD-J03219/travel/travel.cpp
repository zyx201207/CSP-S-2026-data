#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a!=b)
	{
		cout<<"0000";
	}
	else
	{
		string ca,cb;
		for(int i=0;i<2;i++)
		{
			ca+=a1[i];
			cb+=b1[i];
		}
		if(ca!=cb)
		{
			cout<<"1000";
		}
		else
		{
			char a2=a1[2];
			char b2=b1[2];
			if((a2=='C'&&b2=='B')||(a2=='B'&&b2=='A')||(a2=='D'&&b2=='F')||(a2=='A'&&b2=='B')||(a2=='B'&&b2=='C')||(a2=='F'&&b2=='D'))
			{
				cout<<"1111";
			}
			else if((a2=='C'&&b2=='A')||(a2=='A'&&b2=='C'))
			{
				cout<<"1110";
			}
			else
			{
				cout<<"1100";
			}
		}
	}
	return 0;
} 
