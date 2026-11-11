#include <bits/stdc++.h>
using namespace std;
int a[3000005];
int b[3000005];
int main()
{
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=i;j<=n;j++)
		{
			b[a[i]]++;
		}
		if(b[a[i]]>1)
		{
			int k=lower_bound(a+1,a+i+1,a[i])-a;
			for(int j=k;j<i;j++)
			{
				b[a[j]]--;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
	   cout<<b[i]<<" ";
	}
	return 0;
}
