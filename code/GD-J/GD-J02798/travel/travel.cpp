#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,q=0;
	char w1,w2;
	cin>>c1>>s1>>w1>>c2>>s2>>w2;
	if(c1==c2)//同车 
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			q=1;
		}
		else
		{
			cout<<"00";
		}//同排 
		if(q==1)
		{
			if((w1=='A'||w1=='B'||w1=='C')&&(w2=='A'||w2=='B'||w2=='C'))
			{
				cout<<1;
			}
			else if((w1=='D'||w1=='F')&&(w2=='D'||w2=='F'))
			{
				cout<<1;
			}
			else
			{
				cout<<"00";
				return 0;
			}//同侧 
			if((w1+1==w2||w1-1==w2)&&s1==s2)
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
			if(w1==w2&&(s1+1==s2||s1-1==s2))
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		return 0;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
