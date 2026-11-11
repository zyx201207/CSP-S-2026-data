#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		string p1=s1.substr(0,2),p2=s2.substr(0,2);
		if(p1==p2)
		{
			cout<<'1';
			char p1=s1[2];
			char p2=s2[2];
			if((p1=='A' && (p2=='B' || p2=='C')) || (p1=='B' && (p2=='A' || p2=='C')) || (p1=='C' && (p2=='B' || p2=='A')) || (p1=='D' && p2=='F') || (p1=='F' && p2=='D') || (p2=='A' && (p1=='B' || p1=='C')) || (p2=='B' && (p1=='A' || p1=='C')) || (p2=='C' && (p1=='B' || p1=='A')))
			{
				cout<<'1';
				if((p1=='A' && p2=='B') || (p1=='B' && p2=='A') || (p1=='B' && p2=='C') || (p1=='C' && p2=='B') || (p1=='D' && p2=='F') || (p1=='F' && p2=='D'))
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
				}
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
