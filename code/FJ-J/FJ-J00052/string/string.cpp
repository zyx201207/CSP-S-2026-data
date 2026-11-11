#include <bits/stdc++.h>
using namespace std;
int n,a[10000007];
char c[10000007];
string s="0";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		for(int j=1;j<=a[i];j++)s+=c[i];
	}
	long long l=s.size();
	l--;
	long long ans=0;
	for(long long i=1;i<=l/2;i++)
	{
		//printf("%c %c %d %d\n",s[i],s[l+1-i],i,l+1-i);
		if(s[i]!=s[l+1-i])ans++;
	}
	printf("%lld",ans);
	return 0;
}
