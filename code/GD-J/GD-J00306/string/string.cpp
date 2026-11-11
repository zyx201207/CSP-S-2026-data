#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],sum,n;
char c[N];

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld", &n);
	for(int i=1; i<=n; i++)
	scanf("%lld %c", &a[i], &c[i]),sum+=a[i];
	int x=0;
	int p=0;
	int i;
	for(i=1; i<=n&&x<sum/2; i++)
	{
		if(x+a[i]>=sum/2) 
		{
			p=a[i]-sum/2+x;
			break;
		}
		x+=a[i];
	}
//	printf("%d %d %d\n", x, p, sum);
//	i++;
	int k;
	int ans=0;
	if(p==0) {i++,p=a[i];k=i;}
//	printf("%d %d\n", i, p); 
//	if(sum&1) p--;
	if(p==0) 
	{
		k++,p=a[i];
		if(sum&1) p--;
	}
	else
	{
//		printf("%d %d\n", i, k);
		k=i;
		int s=a[i]-p;
		if(sum&1) p--;
//		printf("%d %d\n", s, p);
		while(p<s)
		{
			if(c[k]!=c[i]) ans+=p;
			s-=p,k++,p=a[k];
//			printf("%d\n", s);
		}
		p-=s;
		if(c[k]!=c[i]) ans+=s;
	}
	if(k==n&&p==0)
	{
		printf("%lld", ans);
		return 0;
	}
	if(p==0) k++,p=a[k];
	for(int j=i-1; j>=1; j--)
	{
		// p当前字符剩余字符数，k当前字符下标
		// j回文字符对应下标，s回文字符剩余数量 
		int s=a[j];
//		printf("%d %d %d\n", k, s, p);
		while(p<s)
		{
			if(c[k]!=c[j]) ans+=p;
			s-=p,k++,p=a[k];
//			printf("%d %d %d\n", s, k, j);
		}
		p-=s;
		if(c[k]!=c[j]) ans+=s; 
	}
	printf("%lld", ans);
	return 0;
}
