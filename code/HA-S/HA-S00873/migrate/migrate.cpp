#include<bits/stdc++.h>
using namespace std;
int a[]={2,1,0};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		printf("%d\n",a[t%3]);
	}
	
	return 0;
}//Æ­·Ö 
