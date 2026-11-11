#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],sum;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=i;j<=n;j++)
		{
			int k;
			cin>>k;
			if(a[i]!=k)
			{
				k=a[i+1];
			}
			else
			{
				a[i]=a[k+1];
				k=a[i+1];
			}
		}
		if(a[i]=i)
		{
			sum+=1;
		}
	}
	cout<<sum;	
	return 0;
}
