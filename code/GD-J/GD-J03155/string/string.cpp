#include<bits/stdc++.h>
using namespace std;
struct d
{
	int sl;
	char zm;
}a[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long t=0,ans=0;
	string s,ss;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i].sl,&a[i].zm);
		t+=a[i].sl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].sl;j++)
		s+=a[i].zm;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i].sl;j++)
		ss+=a[i].zm;
	}
	for(int i=0;i<t;i++)
	if(s[i]!=ss[i])
	ans++;
	printf("%lld",ans/2);
	return 0;
}
