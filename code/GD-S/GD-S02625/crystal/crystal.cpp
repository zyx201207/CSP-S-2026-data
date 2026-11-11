#include <bits/stdc++.h>
#define O 500005
using namespace std;
long long n,m,lst[O],cha[O];
long long r,sum1,sum2,ans = 0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%lld %lld",&n,&m);
	for(long long i = 1;i <= n;++i)
		scanf("%lld",&lst[i]);
	sort(lst + 1,lst + 1 + n);
	for(long long i = 1;i <= n;++i)
		cha[i] = lst[i] - lst[i - 1];
	sum1 = sum2 = 0;
	r = n;
	for(long long l = n;l >= 1;--l)
	{
		sum1 += cha[l + 1];
		sum2 += sum1;
//		cout << sum1 << " " << sum2 << endl;
		while(sum2 > m)
		{
			sum2 -= cha[r] * (r - l);
			sum1 -= cha[r];
			--r;
//			cout << sum1 << " " << sum2 <<" " << l << " " <<  r << endl;
		}
		ans = max(r - l + 1,ans);
	}
	cout << ans << endl;
}

/*
注意到,对于一段被选择的区间[l,r]
其代价为
cha[l] + 2 * cha[l + 1] + 3 * cha[l + 2] + ……
于是我们考虑从后往前枚举 

5 8
-3 -1 2 2 7
*/
