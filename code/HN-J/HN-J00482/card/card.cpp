#include <bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	int n,m;
 	cin>>n>>m;
 	int a[n],pai[n];
 	for(int i=0;i<n;i++)
 	{
 		cin>>a[i];
	}
	int num[m+1]={0};
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=0;
		for(int j=i;j<n;j++)
		{
			pai[k]=a[j];	
			for(int q=j-1;q>=0;q--)
			{
				if(pai[k]==pai[q])
				{
					k=q;
				}
			}
			k++;
		}		
		for(int j=0;j<k;j++)
		{
			num[pai[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<num[i]<<' ';
	}
 	return 0;
}
