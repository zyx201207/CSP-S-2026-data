#include<bits/stdc++.h>
using namespace std;
int n,a,a1,b,b1;
char a2,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>a2>>b>>b1>>b2;
	if(a==b)
	{
		cout<<11;
		if((a2!='F'&&a2!='D'&&b2!='F'&&b2!='D')||(a2=='F'&&b2=='D')||a2=='D'&&b2=='F')
		{
			cout<<1;
			if(abs(int(a2)-int(b2))==1)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<"00";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
