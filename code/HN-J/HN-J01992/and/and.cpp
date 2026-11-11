#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for (int i=30;i>=0;i--)
	{
		int x=0;
		for (int j=1;j<=n;j++)
			if(a[j]&(1<<i))
				x++;
		if(x<m) continue;
		ans+=(1<<i);
		for (int j=1;j<=n;j++)
			if(!(a[j]&(1<<i)))
				a[j]=0;
	}
	printf("%d",ans);
	return 0;
}
