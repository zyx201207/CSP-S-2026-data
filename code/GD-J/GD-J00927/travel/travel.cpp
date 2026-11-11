#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		cout<<1;
		string l1,l2;
		l1 = s1[0],l2 = s2[0];
		l1+=s1[1],l2+=s2[1];
		if(l1 == l2)
		{
			cout<<1;
			char a1,a2;
			a1 = s1[2],a2=s2[2];
			if(a1>='A' && a1<='C' && a2>='A' && a2<='C')
			{
				cout<<1;
				if(abs(a1-a2)==1) cout<<1;
				else cout<<0;
			}
			else if(a1>='D' && a1<='F' && a2>='D' && a2<='F')
			{
				cout<<"11";
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
