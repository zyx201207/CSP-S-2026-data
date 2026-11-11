#include<bits/stdc++.h> 
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,max=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(max<a[i])
			{
				max=a[i];	
			}	
		}
		printf("%d",max);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
