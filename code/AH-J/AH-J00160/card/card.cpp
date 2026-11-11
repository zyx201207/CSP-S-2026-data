#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","R",stdin);
	freopen("card.out","W",stdout);
	int n,m;
	long long a[500001],b[500001],s[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(b[j]==a[i])
				{
					while(j<i)
					{
						j++;
						b[j]=0;
					}
				}
			}
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++)if(b[i]!=0)s[b[i]]++;
	}	
	for(int i=1;i<=n;i++)cout<<s[i];
	return 0;
}
