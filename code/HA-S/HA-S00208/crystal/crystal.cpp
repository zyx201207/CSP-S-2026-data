#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long ans;
long long l,r;
long long sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	l=1;
	for(r=1;r<=n;r++)
	{
		sum+=(r-l)*(a[r]-a[r-1]);
//		cout<<r<<": "<<sum<<endl;
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
//		cout<<r<<": "<<l<<"->"<<r<<" "<<sum<<endl;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}
