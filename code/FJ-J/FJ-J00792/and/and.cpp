#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b,c,d[100000000];
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c;
		while(c>0)
		{
			d[i]+=c%2;
			d[i]*=10;
		} 
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(d[i-1]%10==1)
			{
				if(d[i-1]%100/10==1)
				{
					if(d[i-1]%1000/100==1)
					{
						if(d[i-1]%10000/1000==1)
						{
							cout<<d;
						}
						cout<<d;
					}
					cout<<d;
				}
				cout<<d;
			}
			cout<<d;
		}
		cout<<d;
	}
	cout<<d;
	return 0;
} 
