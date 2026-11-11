#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]); 
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=2;i<=m;i++)
	{
		ans=(ans&a[n-i+1]);
	}
	printf("%d",ans);
	return 0;
}
