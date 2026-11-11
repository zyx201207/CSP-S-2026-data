#include <cstdio>
#include <algorithm>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],cnt;
long long sum[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
		if(a[i]>=a[i-1]) cnt++;
	}
	if(cnt==n)
	{
		for(int i=1;i<=m;i++) sum[i]+=sum[i-1],printf("%lld ",sum[i]);
		return 0;
	}
	return 0;
}
