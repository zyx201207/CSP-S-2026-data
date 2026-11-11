#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000010],s=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t>0)
	{
		s=0;
		scanf("%d%d",&n,&d);
		for(int i=0;i<n;i++)scanf("%d",&x[i]);
		for(int i=0;i+d+2<=n;i++)s++;
		printf("%d\n",s);
		t--;
	}
	return 0;
}
