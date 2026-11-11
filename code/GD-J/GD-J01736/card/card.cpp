#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],cnt[500100],num[500100],nex[500100],las[500100];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]); 
		num[i]=1;
		nex[las[a[i]]]=i;
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(nex[i])
		{
			num[nex[i]]+=num[i];
		}
		else
		{
			cnt[a[i]]+=num[i];
			num[i+1]+=num[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",cnt[i]);
	}
	return 0;
}
/*
Trick||Treat!
*/
