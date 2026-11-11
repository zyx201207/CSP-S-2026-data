#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int l[300005];
bool A;
int ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	A=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		l[a[i]]=max(l[a[i]],i);
	for(int i=n;i>=1;i--)
	{
		int x=i;
		while(x<=n)
		{
			++ans[a[x]];
			x=l[a[x]]+1;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
/*
4 2
3 15 12 12



*///
