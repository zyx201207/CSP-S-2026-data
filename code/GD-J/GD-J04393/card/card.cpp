#include<bits/stdc++.h>
using namespace std;
int a[500010];
int c[300010];
int s[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=0;
		for(int j=i;j<n;j++)
		{
			int l=0;
			for(;l<k;l++)
			{
				if(s[l]==a[j])
				{
					break;
				}
			}
			for(;l<k;)
			{
				s[l]=0;
				k--;
			}
			s[k]=a[j];
			k++;
		}
		for(int j=0;j<k;j++)
		{
			c[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
