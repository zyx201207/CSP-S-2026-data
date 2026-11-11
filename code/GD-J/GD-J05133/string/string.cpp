#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,ans;
string s;
struct node
{
	LL num;
	char c;
}a[200008];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%c",&a[i].num,&a[i].c);
		for (int j=1;j<=a[i].num;j++)
			s+=a[i].c;
	}
	LL len=s.size();
	for (int i=0;i<=len/2;i++)
	{
		if (s[i]!=s[n-i+1])
		{
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
