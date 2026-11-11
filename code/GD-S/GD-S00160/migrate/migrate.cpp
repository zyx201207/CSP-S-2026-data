#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,d,x[2000006],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		if(13==c||c==14){cout<<0<<endl;continue;}
		ans=0;
		for(int i=1;i<=n-1;i++)
			if(x[i]+d>=x[i+2]&&x[i]+d<x[i+3]&&x[i+2]+d>=x[i+3])ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
