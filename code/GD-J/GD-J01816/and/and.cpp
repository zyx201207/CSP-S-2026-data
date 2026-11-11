#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ok=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1)cout<<a[n-1];
	else if(m==n)
	{
		int ma=a[0];
		for(int i=1;i<n;i++)
		{
			ma&=a[i];
		}
		cout<<ma;
	}
	else if(m==2)
	{
		int ma=-1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ma=max(ma,(a[i]&a[j]));
			}
		}
		cout<<ma;
	}
	else if(a[n-1]==4)
	{
		int ma1=0,ma2=0,ma3=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)ma1++;
			if(a[i]==2)ma2++;
			if(a[i]==3)ma3++;
		}
		if(n-ma1-ma2-ma3>=m)cout<<4;
		else if(ma3>=m)cout<<3;
		else if(ma3>=1&&ma2>=m-ma3)cout<<2;
		else if(ma3>=1&&ma1>=m-ma3)cout<<1;
		else
		{
			if(ma2>=m)cout<<2;
			if(ma1>=m)cout<<1;
			else cout<<0;
		}
 	}
	else if(a[n-1]==n-1)
	{
		cout<<a[n-m];
	}
	else if(m==3)
	{
		int ma=-1;
		for(int i=0;i<n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				for(int z=j+1;z<n;z++)
				{
					ma=max(ma,(a[i]&a[j]&a[z]));
				}
			}
		}
		cout<<ma;
	}
	else if(m==4)
	{
		int ma=-1;
		for(int i=0;i<n-3;i++)
		{
			for(int j=i+1;j<n-2;j++)
			{
				for(int z=j+1;z<n-1;z++)
				{
					for(int f=z+1;f<n;f++)ma=max(ma,(a[i]&a[j]&a[z]&a[f]));
				}
			}
		}
		cout<<ma;
	}
	else if (a[0]==a[n-1])cout<<a[0];
	else if(m==n-1)
	{
		int ma=0;
		for(int i=0;i<n;i++)
		{
			int x=a[i],y=a[0];
			if(i==0)y=a[1];
			for(int j=0;j<n;j++)
			{
				if(a[j]!=x)y&=a[j];
			}
			ma=max(ma,y);
		}
		cout<<ma;
	}
	else
	{
		cout<<a[n-m];
	}
	return 0;
}
