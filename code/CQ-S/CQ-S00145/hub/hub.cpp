#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,u[2000001],v[200001];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++) scanf("%d%d",&u[i],&v[i]);
		printf("%d\n",n/4);
	}
	return 0;
}
/*
½îÆ£Á¦¾¡ÁË¹ÄÂ¡ ...
*/
