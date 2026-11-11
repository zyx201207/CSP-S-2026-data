#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int N=5e5+5;

int n;LL m;
LL a[N];
LL s[N];
int ans;

LL cost(int l,int r)
{
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for (int i=1,l=1;i<=n;i++)
	{
		while (cost(l,i)>m)
		{
			l++;
		}
		// printf("[%d,%d]:%lld\n",i,l,cost(l,i));
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/