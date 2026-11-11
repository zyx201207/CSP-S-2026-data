#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
const int inf = 0x3f3f3f3f;
int n,m;
int a[N];
int c1[N];
int c2[N];
int ans;
int cal(int n,int m)
{
	return (m-n+1)*c1[m]-c2[m-1]+c2[n-2];
}
int find(int num)
{
	int l=1,r = num;
	int mid = (l+r)>>1;//length
	while(l<r)
	{
		mid = (l+r)>>1;
		//cout<<mid<<endl;
		if(cal(num-mid+1,num)<=m)
		{
			l = mid+1;
		}
		else r = mid;
	}
	return r;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) 
	{
		c1[i] = a[i]-a[i-1];
		c1[i] += c1[i-1];
	}
	for(int i=2;i<=n;i++) 
	{
		c2[i] = c1[i]+c2[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		ans = max(find(i),ans);
	}
	printf("%lld",ans);
}

