#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],s[200005],num,x,ans,p,w,o;
int f(int k)
{
	for(int i=0;i<=50;i++)
	{
		if((1<<i)-1==k)
		{
			return 1;
		}
	}
	return 0;
}
int f1(int k)
{
	for(int i=0;i<=50;i++)
	{
		if((1<<i)==k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(f(a[i])==0)
		{
			p=1;
		}
		if(a[i]!=i-1)
		{
			w=1;
		}
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n)
	{
		x=a[1];
		for(int i=2;i<=n;i++)
		{
			x=(x&a[i]);
		}
		cout<<x;
	}
	else if(p==0)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(f1(n)==1&&w==0)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m];
	}
	else if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i>1)
			{
				o=a[1];
				for(int j=2;j<=n;j++)
				{
					if(i!=j)
					{
						o=(o&a[j]);
					}
				}
			}
			else
			{
				o=a[n];
				for(int j=1;j<n;j++)
				{
					if(i!=j)
					{
						o=(o&a[j]);
					}
				}
			}
			ans=max(ans,o);
		}
		cout<<ans;
	}
	else if(n<=20)
	{
		for(int i=1;i<(1<<n);i++)
		{
			num=0;
			if(__builtin_popcount(i)!=m)
			{
				continue;
			}
			for(int j=0;j<i;j++)
			{
				if(i&(1<<j))
				{
					num++;
					s[num]=a[j+1];
//					cout<<a[j+1]<<" ";
				}
			}
//			cout<<"\n";
			x=s[1];
			for(int j=2;j<=num;j++)
			{
				x=(x&s[j]);
			}
//			cout<<"x:"<<x<<"\n";
			ans=max(ans,x);
		}
		cout<<ans;
	}
	else if(n<=2000&&m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==i)
				{
					continue;
				}
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	return 0;
}
