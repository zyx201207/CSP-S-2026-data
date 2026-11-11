#include<bits/stdc++.h>
using namespace std;
struct car
{
	int c;
	string s;
}a[3];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int b[5];
	cin>>a[1].c>>a[1].s>>a[2].c>>a[2].s;
	if(a[1].c!=a[2].c)
	{
		cout<<"0000";
		return 0;
	} 
	if(a[1].c==a[2].c)
	{
		b[1]=1;
		if(a[1].s==a[2].s)
		{
			cout<<"1111";
			return 0;
		} 
		else
		{
			if(a[1].s[1]==a[2].s[1]&&a[1].s[2]==a[2].s[2])
			b[2]=1;
			else b[2]=0;
			if(a[1].s[3]=='A'&&a[1].s[3]=='B'&&a[1].s[3]=='C')
			{ 
				{
					b[3]=1;
					if((a[1].s[3]-'0')-(a[2].s[3]-'0')==1)
					b[4]=1;
				}
		    }
			if(a[1].s[3]=='D'&&a[1].s[3]=='F')
			{
				if(a[2].s[3]=='D'&&a[2].s[3]=='F')
				{
					b[3]=1;
					if((a[1].s[3]-'0')-(a[2].s[3]-'0')==1)
					b[4]=1;
				}
			}
			else
			{
				b[3]=0;
				b[4]=0;
			} 
		}
	}
	cout<<b[1]<<b[2]<<b[3]<<b[4]<<endl; 
	return 0;
} 
