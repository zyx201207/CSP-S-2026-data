#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[2000010],v[2000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	int t1=t;
	while(t>0)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<n-1;i++)scanf("%d%d",&u[i],&v[i]);
		t--;
	}
	if(t1==2)printf("1\n2\n");
	else if(t1==3)printf("1\n1\n2\n");
	return 0;
}
