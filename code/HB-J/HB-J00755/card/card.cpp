
#include <bits/stdc++.h>
int n,m,a[500005],b[500005],lop=1,bo=1,s;
using namespace std;
int main()
{
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		bo=1;
		cin>>s;
		if(a[lop-1]!=0)
		{
			for(int i=1;i<lop;i++)
			{
				if(a[i]==s)
				{
					bo=0;
				}
				if(bo==0)
				{
					a[i]=0;
				}
			}
		}
		a[lop++]=s;
		for(int i=1;i<lop;i++)
		{
			b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i];
	}
	return 0;
}

