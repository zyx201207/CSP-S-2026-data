#include<bits/stdc++.h>
using namespace std;

int n, aa;
long long ans;
struct stt
{
	long long a;
	char c;
}s[200010];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %c", &aa, &s[i].c);
		s[i].a = s[i - 1].a + aa;
	}
	long long l = 0, r = s[n].a, li = 1, ri = n;
	//printf("%lld", r);
	while(l < r && li <= ri - 1)
	{
		//printf("%lld, %lld, %lld, %lld, %lld, %lld, %c, %c, ", l, r, li, ri, s[li].a - l, r - s[ri - 1].a, s[li].c, s[ri - 1].c);
		if(s[li].a - l < r - s[ri - 1].a)
		{
			if(s[li].c != s[ri].c)
			{
				ans += s[li].a - l;
			}
			r -= s[li].a - l;
			l = s[li].a;
			li++;
		}
		if(s[li].a - l > r - s[ri - 1].a)
		{
			if(s[li].c != s[ri].c)
			{
				ans += r - s[ri - 1].a;
			}
			l += r - s[ri - 1].a;
			r = s[ri - 1].a;
			ri--;
		}
		if(s[li].a - l == r - s[ri - 1].a)
		{
			if(s[li].c != s[ri].c)
			{
				ans += s[li].a - l;
			}
			l = s[li].a;
			r = s[ri - 1].a;
			ri--;
			li++;
		}
		//printf("%lld\n", ans);
	}
	printf("%lld", ans);		
	return 0;
}
