#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		bool flag=0;
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i]) flag=1;
		}
		if(flag==1)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<1;
			if(s1[2]>='D'&&s2[2]>='D')
			{
				cout<<"11";
			}
			else if(s1[2]<='C'&&s2[2]<='C')	
			{
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}
