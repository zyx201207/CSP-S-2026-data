#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;
ll a[N],n;
char c[N]; 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)cin >> a[i] >> c[i];
	ll l = 1,r = n,ans = 0;
	ll cntl = a[1],cntr = a[n];
	while(l < r)
	{
		if(c[l] == c[r] && cntl == cntr)
		{
			l ++; r --;
			cntl = a[l]; cntr = a[r]; 
			continue;
		}
		if(c[l] == c[r])
		{
			if(cntl > cntr)
			{r --;cntl -= cntr; cntr = a[r];} 
			else
			{l ++; cntr -= cntl;cntl = a[l];}
			continue;
		}
		ans += min(cntl,cntr);
		if(cntl > cntr)
		{r --;cntl -= cntr; cntr = a[r];} 
		else if(cntl < cntr)
		{l ++; cntr -= cntl;cntl = a[l];}
		else
		{
			l ++;r --;
			cntr = a[r];cntl = a[l];
		}
	} 
	printf("%lld",ans);
	return 0;
} 
/*
Trick||Treat!
*/
