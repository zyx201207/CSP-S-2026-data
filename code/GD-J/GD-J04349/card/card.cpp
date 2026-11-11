#include<bits/stdc++.h>
using namespace std;
int a[500050],b[1000050],an[300030];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,top=0;
	bool bo=1;
	cin>>n>>m;
	for(int i=1;i<=n;++i) 
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) bo=0;
	}
	if(bo&&n>1000)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)
			{
				if(j==i||a[j]>a[j-1]) ++an[a[j]];
			}
		}
		for(int i=1;i<=m;++i) cout<<an[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		top=0;
		for(int j=i;j<=n;++j)
		{
			int x=a[j];
			for(int k=top;k>=1;--k)
			{
				if(b[k]==x)
				{
					top=k-1;
					break;
				}
			}
			++top;
			b[top]=x;
		}
		for(int i=1;i<=top;++i) ++an[b[i]];
	}
	for(int i=1;i<=m;++i) cout<<an[i]<<' ';
	return 0;
}
