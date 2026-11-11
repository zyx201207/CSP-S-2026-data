#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m;
long long a[maxn], pre[maxn];
int find(int pos)
{
	int l=1, r=pos;
	while(l<r)
	{
		int mid=(l+r)/2;
		int len=pos-mid;
		long long w=pre[pos-1]-pre[mid-1];
		long long cost=a[pos]*len-w;
		if(cost>m)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	int len=pos-l+1;
	return len;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	for(int i=1; i<=n; i++)	scanf("%lld", &a[i]);
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		ans=max(ans, find(i));
	}
	printf("%d", ans);
	return 0;
}
