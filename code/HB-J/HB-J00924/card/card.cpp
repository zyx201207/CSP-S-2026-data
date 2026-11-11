#include<bits/stdc++.h>
using namespace std;

int n,m,g[100010]={0};
int a[200010],b[200010];
char s[100010];

int main()
{
	freopen("card.in","r",stdin);
	//freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	for(int l=0;l<n;l++)
	{
		s[l]=b[l];
		for(int i=l;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(s[j]==s[i])
				{
					for(int k=j;k<i-1;k++)
					{
						s[k]=0;
					}
				}
			}
		}
		for(int i=l;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[i]==j)
				{
					g[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<g[i]<<" ";
	}
}
