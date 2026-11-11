#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
char c[N] , d[N] , f[N];
ll a[N] , b[N] , e[N];
int main()
{
	freopen("string.in" , "r" , stdin) , freopen("string.out" , "w" , stdout);
	int n;
	cin>>n;
	ll all = 0;
	for(int i = 1;i <= n;i++)cin>>a[i]>>c[i] , all += a[i];
	all = all / 2;
	ll sum = 0;
	int len1 = 0;
	for(int i = 1;i <= n;i++)
	{
		if(sum + a[i] <= all)b[++len1] = a[i] , d[len1] = c[i] , sum += a[i] , a[i] = 0;
		else
		{
			a[i] -= all - sum;
			b[++len1] = all - sum , d[len1] = c[i];
			sum += all - sum;
			break;
		}
	}
	int len2 = 0;
	bool fc = all % 2;
	for(int i = 1;i <= n;i++)
	{
		if(fc == 1 && a[i] > 0)
		{
			a[i]--;
			fc = 0;
		}
		if(a[i] > 0)e[++len2] = a[i] , f[len2] = c[i];
	}
	int l = 1 , r = len2;
	ll ans = 0;
	while(l <= len1)
	{
		ll cs = min(b[l] , e[r]);
		if(d[l] != f[r])ans += cs;
		b[l] -= cs , e[r] -= cs;
		if(b[l] == 0)l++;
		if(e[r] == 0)r--;
	}
	cout<<ans;
	return 0;
}
