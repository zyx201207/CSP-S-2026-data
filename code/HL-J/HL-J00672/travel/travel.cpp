#include<bits/stdc++.h>
using namespace std;
char c[5];
char d[5];
int a[6];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,f=0;
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>c[i];
	}
	cin>>c2;
		for(int i=1;i<=3;i++)
	{
		cin>>d[i];
	}
	if(c1==c2)
	{
		a[0]=1;
		
	}
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(c[1]==d[1]&&c[2]==d[2])
	{
		a[1]=1;
		if(c[3]<'D'&&d[3]<'D')
		{
			
			a[2]=1;
			f=1;
			 if(c[3]>='D'&&d[3]>='D')
			{
				a[2]=1;
				f=1; 
			}
		 } 
	}
	if(f!=0)
	{
		if(c[3]=='A'&&d[3]=='B')
		{
			a[3]++;
		}
		if(c[3]=='B')
		{
			if(d[3]=='A'||d[3]=='C')
			{
			
			a[3]++;
		}
}
			if(c[3]=='C'&&d[3]=='B')
		{
			a[3]++;
		}
			if(c[3]=='D'&&d[3]=='F')
		{
			a[3]++;
		}
			if(c[3]=='F'&&d[3]=='D')
		{
			a[3]++;
		}
		}
for(int i=0;i<=3;i++)
{
	cout<<a[i];
}

   return 0;
}


