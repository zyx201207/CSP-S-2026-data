#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)	cout<<"0000";
	else
	{
		cout<<'1';
		int bb=0;
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i]) bb=1;
		}
		if(bb==1) cout<<"000";
		else
		{
			cout<<'1';
			if((s2[2]=='D'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='D'))	cout<<"00";
			else if((s2[2]-s1[2]>2)||(s1[2]-s2[2]>2))	cout<<"00";
			else if((s1[2]=='B'&&s2[2]=='D')||(s2[2]=='B'&&s1[2]=='D'))cout<<"00";
			else if((s1[2]=='C'&&s2[2]=='E')||(s2[2]=='C'&&s1[2]=='E'))cout<<"00";
			else
			{
				if((s2[2]=='D'&&s1[2]=='E')||(s2[2]=='E'&&s1[2]=='D'))	cout<<"11";
				else
				{
					cout<<'1';
					if((s2[2]-s1[2]==1)||(s1[2]-s2[2]==1)) cout<<'1';
					else cout<<'0';
				}
			}
		}
	}
	return 0;
}
