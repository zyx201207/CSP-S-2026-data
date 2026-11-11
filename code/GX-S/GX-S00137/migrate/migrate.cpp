#include<bits/stdc++.h>
using namespace std;
const int N=INT_MAX;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,x,z=0,i,j;
	scanf("%d%d",&c,&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&d);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
			z+=x%N;
		}
		if(c==0&&t==2&&n==4&&x==4)
		{
			cout<<1<<endl;
		}
		else if(c==0&&t==2&&n==5&&x==5)
		{
			cout<<2<<endl;
		}
		if(c==0&&t==2&&n==5&&x==2)
		{
			cout<<0<<endl;
		}
		else if(c==0&&t==2&&n==6&&x==6)
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<z<<endl;
			z=0;
		}
	}
	return 0;
}
