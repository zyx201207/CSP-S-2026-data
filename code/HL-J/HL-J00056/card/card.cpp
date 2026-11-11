#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[500010],c[500010],cnt,s[500010];
int k[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>n>>m;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sum=n;
	while(sum)
	{
		a[sum]=0;
		sum--;
		for(int i=1;i<=n;i++)
		{
			if(k[a[i]])
			{
				cnt++;
				s[cnt]=a[i];
				k[a[i]]=cnt;
			}	 
			else
			{
				int u=cnt;
				for(int j=k[a[i]];j<=u;j++)
				{
					cnt--;
					k[s[j]]=0;
					s[j]=0;
				}
			}
		} 
		for(int i=1;i<=n;i++)
		{
			c[a[i]]++;
		}
		
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
