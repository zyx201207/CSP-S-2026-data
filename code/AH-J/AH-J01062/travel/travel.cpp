#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	char a2[5],b2[5];
	bool n1,n2,n3,n4;
	cin>>a1;
	for(int i=0;i<3;i++)
	{
		cin>>a2[i];
	}
	cin>>b1;
	for(int i=0;i<3;i++)
	{
		cin>>b2[i];
	}
	if(a1==b1)
	{
		n1=1;
		cout<<n1;
	}
	else
	{
		n1=0;
		cout<<n1;
	}
	n2=0;
	if(a2[0]==b2[0]&&n1==1)
	{
		if(a2[1]==b2[1])
		{	
			n2=1;
			cout<<n2;
		}
		else
		cout<<n2;
	}
	else
	cout<<n2;
	n3=0;
		if(n1==1&&n2==1)
		{
			n3=1;
			if( (a2[2]=='D'&&b2[2]=='C') || (a2[2]=='C'&&b2[2]=='D') )
			{
			n3=0;
			cout<<n3;
			}
			else
			cout<<n3;
		}
		else
		cout<<n3;
	n4=0;
		if(n1==1&&n2==1&&n3==1)
		{
			if((a2[2]-1)==b2[2]||(a2[2]+1)==b2[2])
			{
			n4=1;
			cout<<n4;
			}
			else
			cout<<n4;
		}
		else
		cout<<n4;
	return 0;
}
