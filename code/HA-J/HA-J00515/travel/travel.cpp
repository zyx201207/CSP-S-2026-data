#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2;
    string s1[3];
    string s2[3];
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1!=c2)
	{
		cout<<0<<0<<0<<0;
	}
	else if(c1==c2)
	{
	    cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
		}
		else if(s1[3]==s2[3])
		{
			cout<<1<<0;
		}
	    else
		{
			cout<<1<<1;
		}		
	}	
	return 0;
} 
