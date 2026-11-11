#include<bits/stdc++.h>
using namespace std;
bool a[200005][31];
int b[200005];
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	scanf("%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int j;
		scanf("%d",&j);
		b[i]=j;
		for(int k=0;k<=29;k++)
		{
			if(j%2==1)
			{
				a[i][30-k]=1;
			}
			else
			{
				a[i][30-k]=0;
			}
			j=j/2;
		}
	}
	bool l;
	for(int i=1;i<=m;i++)
	{
		
	}
	printf("%d",);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
 } 
