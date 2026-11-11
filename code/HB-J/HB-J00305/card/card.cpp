#include<bits/stdc++.h>
using namespace std;
int n,a[500050],m,book[300050],zh[500050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int cn=0;
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<cn;k++)
			{
				if(zh[k]==a[i])
				{
					for(int l=0;l<=k;l++)
					{
						zh[l]=-1;
					}
					break;
				}
			}
			zh[cn++]=a[j];
		}
		for(int k=0;k<cn;k++)
		{
			if(zh[k]>0)book[zh[k]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<book[i]<<' ';
	return 0;
}

