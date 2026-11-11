#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cy[510000],n,m,ans,add;int v;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&cy[i]);
	}
	sort(cy+1,cy+n+1);
	for(int i=2;i<=n;i++)
	{
		v=i,add=0;
		while(add+cy[i]-cy[v-1]<=m&&v>1){v--;add+=cy[i]-cy[v];}
		ans=max((long long)i-v+1,ans);
	}
	printf("%lld",ans);
	return 0;
}
