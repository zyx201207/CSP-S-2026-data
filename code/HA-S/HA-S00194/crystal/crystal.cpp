#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int savem=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum1=0;
	
	for(int i=2;i<=n;i++)
	{
		int num1=1;
		bool ju=true;
		m=savem;
		while(ju)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(m-a[i]+a[j]==0)
				{
					m+a[j]-a[i];
					num1++;
					ju=false;
				}
				else if(m-a[i]+a[j]>0)
				{
					m+a[j]-a[i];
					num1++;
				}
				else
				{
					ju=false;
					break;
				}
			}
				
		}
		if(num1>sum1)
		{
			sum1=num1;
		}	
	}
	cout<<sum1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
