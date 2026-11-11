#include<bits/stdc++.h> 
using namespace std;
long long a[500010];
int main()
{
	freopen("crystal4.in","r",stdin);
	freopen("crystal4.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int l=1,r=1;
	long long maxn=1;
	long long sum=0,ans=1;
	while(r<n&&l<=n)//l~r
	{
		if(sum+ans*(a[r+1]-a[r])<=m)
		{
			sum+=ans*(a[r+1]-a[r]);
			ans++;
			r++;
			maxn=(maxn>ans?maxn:ans);
		}
		else
		{
			ans--;
			sum-=a[r]-a[l];
			l++;
		}
	}
	printf("%lld",maxn);
	return 0;
}
