#include<bits/stdc++.h>
using namespace std;
int n,m,num[500003],a,b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	a=rand()%10;
	for(int i=0;i<a;i++)
	{
		b=rand()%n;
		printf("%d",b);
	}
}
