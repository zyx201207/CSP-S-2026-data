#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=1;i<m;i++)
	{
		sum=sum&a[n-i];
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
