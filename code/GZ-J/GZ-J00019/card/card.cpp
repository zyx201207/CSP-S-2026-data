//GZ-J00019 µËÔÆÐù
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],d[500005];
bool c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
		    b[j]=a[j];
		    c[j]=0;
		}
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<j;k++)
			{
				if(a[k]==a[j]&&!c[k])
			    {
				    for(int f=k;f<j;f++)
					{
					    b[f]=0;
					    c[f]=1;
					}
			    }
			}
		}
		for(int j=i;j<=n;j++)
		{
			d[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << d[i] << " ";
	}
	return 0;
}
