#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;ll m;
ll a[N];//<=1e12
ll sum[N];//<=5e17
ll getsum(int lft,int rgt,int r)
{
	return (rgt - lft + 1) * a[r] - sum[rgt] + sum[lft - 1];
}
int l,r,ans,mid;
ll get(int x)
{
	l = 1;
	r = x - 1;
	ans = x;
	while(l <= r)
	{
		mid = (l + r) >> 1;
//		cout<<mid<<" "<<x<<" "<<getsum(mid,x - 1,x)<<endl;
		if(getsum(mid,x - 1,x) <= m)
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return x - ans + 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	sum[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		sum[i] = a[i] + sum[i - 1];
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != a[i + 1] || i == n)
		{
			ans = max(ans,get(i));
//			cout<<get(i)<<endl;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

