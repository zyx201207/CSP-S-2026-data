#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n],s[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		
		sum=0;
		for(int j=i-1;j<=n;j++)
		{
			for(int k=i-1;k<n;k++)
			{
				if(a[j]==a[k])
				{
					for(int p=k;p<j;p++)
					{
						a[p]=0;
					 } 
				}
				
			}
			sum+=a[j];
		}
		if(s[i]=s[i])
		{
			s[i]+=i-1;
		}
		
		
	}
	for(int i=1;i<=n-1;i++)
	{
		cout<<s[i]<<" ";
	}
	return 0;
}//ccfkbl 


