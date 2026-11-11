#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (m==1)
	{
		int Max=0;
		for (int i=1;i<=n;i++)
			Max=max(Max,a[i]);
		cout<<Max;
	}
	if (m==2)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
				sum=max(sum,a[i]&a[j]);
		}
		cout<<sum;
	}
	else if (m==n)
	{
		int sum=a[1];
		for (int i=2;i<=n;i++)
			sum=sum&a[i];
		cout<<sum;
	}
	else if (n>2000)
	{
		sort(a+1,a+n+1);
		int sum=a[n];
		for (int i=1;i<m;i++)
			sum=sum&a[i];
		cout<<sum;
	}
	else if (m==3)
	{
		int sum=0;
		for (int A=1;A<=n;A++)
		{
			for (int b=A+1;b<=n;b++)
			{
				for (int c=b+1;c<=n;c++)
					sum=max(sum,a[A]&a[b]&a[c]);
			}
		}
		cout<<sum;
	}
	else if (m==4)
	{
		int sum=0;
		for (int A=1;A<=n;A++)
		{
			for (int b=A+1;b<=n;b++)
			{
				for (int c=b+1;c<=n;c++)
				{
					for (int d=c+1;d<=n;d++)
						sum=max(sum,a[A]&a[b]&a[c]&a[d]);
				}
			}
		}
		cout<<sum;
	}
	else if (m==5)
	{
		int sum=0;
		for (int A=1;A<=n;A++)
		{
			for (int b=A+1;b<=n;b++)
			{
				for (int c=b+1;c<=n;c++)
				{
					for (int d=c+1;d<=n;d++)
					{
						for (int e=d+1;e<=n;e++)
							sum=max(sum,a[A]&a[b]&a[c]&a[d]&a[e]);
					}
				}
			}
		}
		cout<<sum;
	}
	else if (m==10)
	{
		int sum=0;
		for (int A=1;A<=n;A++)
		{
			for (int b=A+1;b<=n;b++)
			{
				for (int c=b+1;c<=n;c++)
				{
					for (int d=c+1;d<=n;d++)
					{
						for (int e=d+1;e<=n;e++)
						{
							for (int f=e+1;f<=n;f++)
							{
								for (int g=f+1;g<=n;g++)
								{
									for (int h=g+1;h<=n;h++)
									{
										for (int i=h+1;i<=n;i++)
										{
											for (int j=i+1;j<=n;j++)
												sum=max(sum,a[A]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<sum;
	}
	return 0;
}
