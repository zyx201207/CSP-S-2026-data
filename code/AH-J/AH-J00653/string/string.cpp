#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],cnt[200010],ans,answ;
char c[200010];
long long up_bu(long long x)
{
	long long l = 1,r = n,p,mid;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(cnt[mid] >= x)
		{
			p = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return p;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		cnt[i] = cnt[i - 1] + a[i];
	//	ans += a[i];
	}
	for(int i = 1;i <= n && cnt[i - 1] < cnt[n] / 2;i++)
	{
		long long l = cnt[i - 1] + 1,r = (cnt[i] >= cnt[n] / 2) ? (cnt[n] / 2) : cnt[i];
		long long fl = cnt[n] - l + 1,fr = cnt[n] - r + 1;
		if(fl > fr)swap(fl,fr);
		long long dl = up_bu(fl),dr = up_bu(fr);
		for(int j = dl + 1;j <= dr - 1;j++)
			if(c[i] != c[j])ans += a[j];
		if(dl == dr)
		{
			if(c[i] != c[dl])ans += fr - fl + 1;
		}
		else 
		{
			if(c[i] != c[dl])ans += cnt[dl] - fl + 1;
			if(c[i] != c[dr])ans += fr - cnt[dr - 1];
		}
	}
	//long long l,r,lt,rt;
	//if(ans % 2 == 0)l = ans / 2,r = ans / 2 + 1;
	//else l = ans / 2,r = ans / 2 + 2;
	//for(int i = 1;i <= n;i++)
	//{
	//	if(cnt[i - 1] < l && cnt[i] >= l)
	//		lt = i;
	//	if(cnt[i - 1] < r && cnt[i] >= r)
	//		rt = i;
	//}
	//while(l >= 1 && r <= ans)
	//{
	//	if(c[lt] != c[rt])answ++;
	//	//cout << lt << ' ' << rt << ' ' << answ << endl;
	//	l--,r++;
	//	if(l <= cnt[lt - 1])lt--;
	//	if(r > cnt[rt])rt++;
	//}
	//printf("%lld",answ);
	printf("%lld",ans);
	return 0;
}
//100pts
