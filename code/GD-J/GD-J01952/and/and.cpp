#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],choose[200005],maxx=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[n];
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			long long o=0;
			for(int k=1;k<=m;k++)
			{
				choose[j]=a[k];
				if(k==1)
				{
					o=choose[j];
					j++;
					continue;
				}
				o&=choose[j];
			}
			maxx=max(maxx,o);
		}
	}
	cout<<maxx;*/
	return 0;
}
