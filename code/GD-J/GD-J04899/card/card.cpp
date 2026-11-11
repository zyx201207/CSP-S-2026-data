#include<bits/stdc++.h>
using namespace std;
int aa[5005],a[5005],b[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		aa[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)//æ÷ 
		{
			for(int q=j-1;q>=i;q--)// ’ 
			{
				if(a[q]==a[j])
				{
					for(int p=q;p<j;p++)
					{
						a[p]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(a[j]!=0)
			{
				b[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++)
		a[j]=aa[j];
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<" ";
	return 0;
}

