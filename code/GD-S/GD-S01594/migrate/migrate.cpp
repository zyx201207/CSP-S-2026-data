#include <cstdio>
#include <cmath>
using namespace std;
const int N=2e6;
int c,t,x[N];
void solve()
{
	int n,d,cnt=0;scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(x[i]-x[i-1]==1) cnt++;
	}
	if(cnt==n)
	{
		if(d<=(n+1)/2) printf("%d\n",n-3);
		else printf("0\n");
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
