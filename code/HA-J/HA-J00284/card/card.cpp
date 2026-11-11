#include<bits/stdc++.h>
using namespace std;
long long a[300005],b[300005],c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				for(int k=i;k<j;k++)
					a[k]=0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]!=0)
				b[a[j]]++;
		}
		for(int j=i;j<=m;j++)
			a[j]=c[j];
	}
	for(int i=1;i<=m;i++)
		cout << b[i] <<" ";
	return 0;
}
