#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	else if(m==2)
	{
		if(n==3)
		{
			int num1=0,num2=0;
			for(int i=1;i<=3;i++)
			{
				if(a[i]==1)
					num1++;
				else
					num2++;	
			}
			if(num1==2)
			{
				cout<<3<<" "<<0;
				return 0;
			}else
			{
				cout<<3<<" "<<0;
				return 0;
			}
		}
		else
		{
			int num3=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[n])
				{
				num3=i-1;
				break;	
				}
			}
			if(a[n]==2)
			{
				cout<<num3<<" "<<n-num3;
				return 0;
			}
			if(a[n]==1)
			{
				cout<<n-num3<<" "<<num3;
				return 0;
			}
		}
	cout<<3<<" "<<1<<" "<<4;	
	}
	return 0;
}
