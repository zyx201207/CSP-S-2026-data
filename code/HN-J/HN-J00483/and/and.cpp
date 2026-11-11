#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,a[MAXN],ans,m;
long long aa[MAXN];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int  i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=1;i<m;i++)
		ans=ans&a[n-i];
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
