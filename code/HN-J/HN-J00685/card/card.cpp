#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]!=a[i])
		{
			printf("%d ",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
