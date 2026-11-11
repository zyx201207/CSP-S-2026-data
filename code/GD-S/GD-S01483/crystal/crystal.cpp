#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
int n;
long long m,a[N],qz[N];
bool check(int l)
{
	for(int i=1;i+l-1<=n;i++)
	{
		long long r=i+l-1;
		long long nd=a[r]*l-qz[r]+qz[i-1];
		if(nd<=m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];
	int l=1,r=n,be=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) be=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",be);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
