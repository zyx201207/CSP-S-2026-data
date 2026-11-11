#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 2e6 + 5;

ll arr[N],n,d;
ll jmp[N];
void deal_jmp(void)
{
	ll t = n;
	for(ll i = n;i >= 1;i--)
	{
		while(arr[t] - arr[i] > d)
			t--;
		jmp[i] = t;
	}
	return;
}
void func(void)
{
	scanf("%lld%lld",&n,&d);
	for(ll i = 1;i <= n;i++)
		scanf("%lld",arr + i);
	deal_jmp();
	ll sl = 1;
	ll ans = 0;
	while(sl <= n)
	{
		ll sr = sl + 1;
		while(sr <= n && arr[sr] - arr[sr - 1] <= d)
			sr++;
//		printf("area : %lld %lld\n",sl,sr);
		for(ll i = sr - 1;i >= sl;i--)
		{
//			printf("Start : %lld,%lld\n",i,jmp[i]);
			ll l1 = i,r1 = i,l2 = 0,r2 = -1;
			ll res = 0;
			ll lst = i - 1;
			for(ll s = i;s < sr;s = jmp[s])
			{
//				printf("[%lld,%lld] -> [%lld,%lld]\n",lst + 1,s,s + 1,jmp[s]);
//				printf("1 : %lld %lld, 2 : %lld %lld\n",l1,r1,l2,r2);
//				printf("As follow:\n");
//				for(ll r = lst + 1;r <= s;r++)
//					printf("jmp[%lld] = %lld, ",r,jmp[r]);
//				printf("\n");
				res += r2 - l2 + 1;
				if(r1 - l1 + 1 >= 2)
				{
					ll nr1 = jmp[s],nl1 = jmp[r1 - 1] + 1;
					ll nr2 = jmp[r1 - 1],nl2;
					if(r1 - 2 > lst)
						nl2 = jmp[r1 - 2] + 1;
					else
						nl2 = s + 1;
					if(nl1 > nr1)
						nl1 = 0,nr1 = -1;
//					printf("Raise that : %lld %lld (jmp[%lld] = %lld)\n",nl2,nr2,r1 - 1,jmp[r1 - 1]);
					if(nl2 > nr2)
						nl2 = 0,nr2 = -1;
					l1 = nl1,r1 = nr1;
					l2 = nl2,r2 = nr2;
				}
				else if(r1 - l1 + 1 == 1)
				{
					ll nr1 = jmp[s],nl1;
					if(r1 - 1 > lst)
						nl1 = jmp[r1 - 1] + 1;
					else
						nl1 = s + 1;
					if(nl1 > nr1)
						nl1 = 0,nr1 = -1;
					l1 = nl1,r1 = nr1;
					l2 = 0,r2 = -1;
				}
				else if(r2 - l2 + 1 >= 1)
				{
//					printf("GETIN\n");
					ll nr2 = jmp[s],nl2;
					if(nr2 - 1 > lst)
						nl2 = jmp[r2 - 1] + 1;
					else
						nl2 = s + 1;
					if(nl2 > nr2)
						nl2 = 0,nr2 = -1;
					l2 = nl2,r2 = nr2;
				}
				else
					break;
				if(s == jmp[s])
					break;
				lst = s;
			}
//			printf("contribute %lld : %lld\n",i,res);
			ans += res;
		}
		sl = sr;
	}
	printf("%lld\n",ans);
	return;
}
void special_func(void)
{
	scanf("%lld%lld",&n,&d);
//	fprintf(stderr,"n = %lld\n",n);
	for(ll i = 1;i <= n;i++)
		scanf("%lld",arr + i);
	if(n == 1)
	{
		printf("0\n");
		return;
	}
	if(arr[2] - arr[1] > d)
	{
		printf("0\n");
		return;
	}
	deal_jmp();
	ll t = 2 * jmp[1] - 2;
	if(t >= 4)
		printf("%lld\n",max(n - t + 1,0LL));
	else
		printf("0\n");
	return;
}
ll casetype,T;
int main(void)
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&casetype,&T);
	if(casetype == 11 || casetype == 12)
	{
		while(T--)
			special_func();
	}
	else
	{
		while(T--)
			func();
	}
	return 0;
}
