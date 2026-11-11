#include<bits/stdc++.h>
using namespace std;
int n,m;
int p2[32];
int num1[32]={0};
int num2[32]={0};
int num3[32]={0};
int sum[1000000];
int num=0;
int sum1=0;
int sum2=0;
int pp2(int x,int y)
{
	for(int i=1;i<=31;i++)
	{
		if(x>=p2[i])
		{
			num1[i]=1;
		}
		if(x==0)
		{
			break;
		}
	}
	for(int i=1;i<=31;i++)
	{
		if(y>=p2[i])
		{
			num2[i]=1;
		}
		if(y==0)
		{
			break;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		if(sum[i]>num)
		{
			num=sum[i];
		}
	}
	if(m!=2)
	{
		cout<<num;
		return 0;
	}
	p2[31]=1;
	for(int i=30;i>0;i--)
	{
		p2[i]=p2[i+1]*2;
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			pp2(sum[i],sum[j]);
			for(int o=1;o<=31;o++)
			{
				if(num1[o]==1||num2[o]==1)
				{
					sum1+=p2[o];
				}
			}
			if(sum1>sum2)
			{
				sum2=sum1;
			}
			sum1=0;
			for(int i=1;i<=31;i++)
			{
				num1[i]=0;
				num2[i]=0;
			 } 
		}
	}
	cout<<sum2;
} 
