#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n-m;i<=n;i++)
	{
		if(i==n-m)ans=a[i];
		else ans=ans&a[i];
	}
	printf("%d",ans);
	return 0;
}
