#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n]={0};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c=0;//记录水晶 
	for(int i=0;i<n;i++)
	{
		if(a[i]<a[i+1])
		{
			m=m-(a[i+1]-a[i]);
			if(m==0)
			{
				break;
			}
			a[i]=a[i+1];
		}
		else
		{
			m=m-(a[i]-a[i+1]);
			if(m==0)
			{
				break;
			}
			a[i+1]=a[i];
		}
	}
	int t=0;//记录重复 
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			c+=2;
			t++;	
		}
	}
	cout<<c-(t-1);
	return 0;
}
