#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],b[1000005],top[100000],m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int j=n;j>=1;j--)
	{
		int t=0;
		for (int i=n-j+1;i<=n;i++)
		{
			b[++t]=a[i];
			for (int k=1;k<=t;k++)
			{
				if (b[k]==a[i])
				{
					while(t>k)
						b[t--]=0;
				}
			}
			
		}
		for (int i=1;i<=t;i++)
			top[b[i]]++;
	}
	for (int i=1;i<=m;i++)
		cout<<top[i]<<" ";
	return 0;
 } 
