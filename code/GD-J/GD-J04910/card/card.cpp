#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005]={0},s[500005],q=1,w[300005];
int main()
{
	freopen("card.in ","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int s[500005]={0};
		for(int j=i;j<=n;j++)
		{
			s[j]=a[j];
			for(int x=1;x<j;x++)
			{
				if(s[x]==s[q])
				{
					for(int z=x;z<j;z++)s[z]=0;
					break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			a[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<' ';
}
