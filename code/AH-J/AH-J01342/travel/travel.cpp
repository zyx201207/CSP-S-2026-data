#include<bits/stdc++.h>
using namespace std;
string r1,x1;
char a1[100],a2[100];
int z,x,c,v;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>a1>>x1>>a2; 
	if(r1==x1)
	{
		cout<<"1";
		if(a1[0]==a2[0]&&a1[1]==a2[1])
		{
			cout<<"1";
			if(a1[2]>='D'&&a2[2]>='D')
			cout<<"11";
			else if(a1[2]>='A'&&a2[2]>='A')
			{
				cout<<"1";
				if((a1[2]=='A'&&a2[2]=='C')||(a1[2]=='C'&&a2[2]=='A'))
				cout<<"0";
				else cout<<"1";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
