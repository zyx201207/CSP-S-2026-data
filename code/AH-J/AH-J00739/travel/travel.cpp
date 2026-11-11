#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	bool f=true;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			f=false;
		}
		if(f==true)
		{
			cout<<1;
			if(((int)s1[2]<=67&&(int)s2[2]<=67)||((int)s1[2]>67&&(int)s2[2]>67))
			cout<<1;
			else
			cout<<0;
			if(((int)s1[2]=='C'&&(int)s2[2]=='D')||((int)s1[2]=='D'&&(int)s2[2]=='C'))
			cout<<0;
			else if(((int)s1[2]==(int)s2[2]+1)||((int)s1[2]+1==(int)s2[2]))
			cout<<1;
			else
			cout<<0;
		}
		else
		{
			cout<<0;
			cout<<0;
			cout<<0;
		}
    }
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
