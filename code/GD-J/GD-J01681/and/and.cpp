#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
void n20()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=0;
	for(int i=0;i<(1<<n);i++)
	{
		int sum=0,ans=(1<<29)-1;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				sum++;
				ans=ans&a[j+1];
			}
		}
		if(sum==m)
		{
			x=max(x,ans);
		}
	}
	cout<<x;
}
void m1()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1];
		ans=max(ans,a[1]);
	}
	cout<<ans;
}
void mn()
{
	int ans=(1<<29)-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[1];
		ans=ans&a[1];
	}
	cout<<ans;
}
void m2()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,(a[i]&a[j]));
		}
	}
	cout<<ans;
}
void mn_1()
{
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=20;i>=0;i--)
	{
		int x=0,y=1;
		for(int j=1;j<=n;j++)
		{
			if((a[j]>>i)&1)
			{
				x++;
			}
			else
			{
				y=j;
			}
		}
		if(x==n-1)
		{
			int ans=(1<<29)-1;
			for(int j=1;j<=n;j++)
			{
				if(i==y)
				{
					continue;
				}
				else
				{
					ans=ans&a[j];
				}
			}
			cout<<ans;
			return;
		}
	}
	int ans=(1<<29)-1;
	for(int i=1;i<=n;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
}
bool cmp(int x,int y)
{
	return(x>y);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n<=20)
	{
		n20();
	}
	else if(m==1&&n<=2000)
	{
		m1();
	}
	else if(m==n&&n<=2000)
	{
		mn();
	}
	else if(m==2&&n<=2000)
	{
		m2();
	}
	else if(m==n-1)
	{
		mn_1();
	}
	else
	{
		bool x=true;
		int biggestt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]&a[i]+1)
			{
				x=false;
			}
			biggestt=max(biggestt,a[i]);
		}
		if(biggestt<=4)
		{
			int b[6]={0};
			for(int i=1;i<=n;i++)
			{
				b[a[i]]++;
			}
			if(b[4]>=m)
			{
				cout<<4;
				return 0;
			}
			else if(b[3]>=m)
			{
				cout<<3;
				return 0;
			}
			else if(b[2]+b[3]>=m)
			{
				cout<<2;
				return 0;
			}
			else if(b[1]+b[3]>=m)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
		else if(x)
		{
			sort(a+1,a+n+1,cmp);
			cout<<a[m];
		}
		else
		{
			n20();
		}
	}
	return 0;
}
