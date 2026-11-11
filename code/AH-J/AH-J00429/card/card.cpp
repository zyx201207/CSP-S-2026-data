#include <bits/stdc++.h>
const int love=2413;
using namespace std;
int n,m,a[500005],p[500005],now,b[500005],ans[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	
		cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		{
			if(p[a[i]]>=1)
			{
				int num=p[a[i]];
				for(int j=p[a[i]];j<=now;j++)
					p[b[j]]=0;
				now=num-1;
			}
			p[a[i]]=++now;
			b[now]=a[i];
		}
		for(int i=1;i<=m;i++)
			if(p[i]>=1)
				ans[i]++;
		for(int i=1;i<=m;i++)
			p[i]=0;
		now=0;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
