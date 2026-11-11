#include<bits/stdc++.h>
using namespace std;
int n,m,sum=1;
long long a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//排序 
	for(int i=1;i<=n;i++)
	{
		sort(a,a+n);		
	} 
	//验证 
	//遍历a[i]
	for(int i=1;i<=n;i++)
	{
		//判断每次给谁加1 
		for(int j=i;j>=0;j--)
		{
			if(j=0)
			{
				j++;
			}
			a[j-1]+1;
			m--;
			if(m=0)
			{
				break;
			}
		}
		if(a[i]<a[i+1])
		{
			a[i]++;
			m--;
			if(m=0)
			{
				break;
			}
		}
	}  
	for(int i=1;i<=n;i++)
	{
		if(a[i]+1>a[i+1])
		{
			sum++; 
		} 
	}
	cout<<sum;
	return 0;
} 
