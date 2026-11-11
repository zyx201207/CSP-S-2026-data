#include<bits/stdc++.h>
using namespace std;
int n,m,a[11001],x[100001],n1=0,n2=0;
int main()
{
	freopen("card.in","r",stdin);
  	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		if(n%2==0)
		{
			cout<<n; 
		 } 
		 else
		 {
		 	cout<<0;
		 }
	}
	else if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=n-i;j<n;j++)
			{
				x[i]=a[i];
				for(int k=n-i;k<j;k++)
				{
					if(x[j]==x[k])
					{
						for(int z=k;z<j;z++)
						{
							x[z]=0;
						}
					}
				}
			}
			for(int j=n-i;j<n;j++)
			{
				if(x[j]==1)
				{
					n1++;	
				}
				else if(x[j]==2)
				{
					n2++;
				}
			}
		}
		cout<<n1<<" "<<n2;
	} 
	return 0;
}
//good luck ^_^

