#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300010],a[500010],mw[300010];
int main()
{
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{scanf("%d",&a[i]);mw[a[i]]=i;}	
	for(int i=1;i<=n;i++)
	{
		int f=mw[a[i]];
		ans[a[i]]++;
		while(f+1<=n)
			f=mw[a[f+1]],ans[a[f]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
 	return 0;
}
