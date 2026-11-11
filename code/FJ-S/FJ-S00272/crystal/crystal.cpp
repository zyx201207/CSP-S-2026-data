#include <bits/stdc++.h>
#define fr(x)\
	freopen(#x".in","r",stdin);\
	freopen(#x".out","w",stdout);

using std::cin;
typedef long long ll;
constexpr int N=1e6;
int n;ll m;ll a[N],p[N];

inline bool check(int x)
{
	for(int i=1;i+x-1<=n;i++)
	{
		if(a[i+x-1]*x-(p[i+x-1]-p[i-1])<=m)return true;
	}
	return false;
}

int main()
{
	fr(crystal)
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)p[i]=p[i-1]+a[i];
	int L=1,R=n+1,mid;
	while(L+1<R)
	{
		mid=(L+R)>>1;
		if(check(mid))L=mid;
		else R=mid;
	}
	printf("%d\n",L);
	return 0;
}
