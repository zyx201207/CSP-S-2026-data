#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x=n;
	for(;x>=1;x/=2)
	{
		if(x==1)
		{
			printf("%d",n-2);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
