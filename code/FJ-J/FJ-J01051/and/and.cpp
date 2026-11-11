#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[212345],b[2123],sun,sum,cnt=0,ans=0;
void f(int x,int sum1)
{
	if (x==m+1)
	{
		cnt=max(cnt,sum1);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (b[i]==0)
		{
			b[i]=1;
			f(x+1,sum1&a[i]);
			b[i]=0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum=max(sum,a[i]);
		if (a[i]==i-1)
		{
			ans+=1;
		}
		if (a[i]==2)
		{
			sun+=1;
		}
	}
	if (n<=20)
	{
		f(1,(1<<32)-1);
	}
	else
	{
		if (m==1)
		{
			cnt=sum;          
		}
		else              
		{
			if (m==2)
			{
				for (int i=1;i<=n;i++)
				{
					for (int j=i+1;j<=n;j++)
					{
						cnt=max(cnt,a[i]&a[j]);
					}
				}
			}
			else
			{
				if (m==n)
				{
					cnt=a[1];
					for (int i=2;i<=n;i++)
					{
						cnt&=a[i];
					}
				}
				else
				{
					if (sum<=4)
					{
						cnt=sum;
					}
					else
					{
						if (ans==n)
						{
							if (n-sun>=m)
							{
								cnt=sum;
							}
							else
							{
								cnt=2;
							}
						}
						else
						{
							sort (a+1,a+n+1);
							cnt=a[n-m+1];
						}
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
