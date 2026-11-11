#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+5;

int c,t;
ll x[MAXN];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int _=1;_<=t;_++)
	{
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		ll di=d/abs(x[1]-x[2]);
		int ans=0;
		if(di==0||di==1||di==n||di==n<<1)
		{
			printf("0\n");
			continue;
		}
		ans+=n-(di+2)+1;
		printf("%d\n",ans);
	}
	
	return 0;
}
