#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string c1 ,c3;
	char c2[4],c4 [4];
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>c2[i];
	}
	cin>>c3;
	for(int i=1;i<=3;i++)
	{
		cin>>c4[i];
	}
	
	//11111111111111111111111
	int k=0;
	if(c1==c3)
	{
		cout<<"1";
		k=1;
	}
	else
	{
		cout<<"0";
	}
	
	//22222222222222222222
	int f=0;
if(k==1)
{

	if(c2[1]==c4[1])
	{
		if(c2[2]==c4[2])
		{
			cout<<"1";
			f=1;
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		cout<<"0";
	}
}
else
{
	cout<<"0";
}
	int j=0;
	// 3333333333333333333333
	if(f==1)
	{
		if(c2[3]=='F'||c4[3]=='D'&&c4[3]=='F'||c2[3]=='D')
		{
			cout<<"1";
			j=1;
		}
		else if(c2[3]=='C'&&c4[3]=='D'||c2[3]=='D'&&c4[3]=='C')
		{
			cout<<"0";
		}
		else
		{
			if(c2[3]=='A'||c2[3]=='B'||c2[3]=='C'&&c4[3]=='A'||c4[3]=='B'||c4[3]=='C')
			{
				cout<<"1";
				j=1;
			}
			else
			{
				
				cout<<"0";
				
				
			}
		}
	}
	else
	{
		cout<<0;
	}
	
	//444444444444444444444
	
	if(c2[3]=='F'||c2[3]=='D')
	{
		if(c4[3]=='F'||c4[3]=='D')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else
	{
		if(j==1)
		{
		
			if(c2[3]+1==c4[3]||c2[3]-1==c4[3])
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
		else
		{
			cout<<"0";
		}
	}
	return 0;
 } 
