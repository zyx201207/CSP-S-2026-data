#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],head=1,tail,q[500005],sum,l,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	q[++tail]=a[1];
	for(long long i=2;i<=n;i++)
	{
		q[++tail]=a[i];
		sum+=l*(a[tail]-a[tail-1]);
		while(sum>m)
		{
			head++;
			sum-=(a[tail]-a[head]);
		}
		l=tail-head+1;
		ans=max(ans,l);
	}
	cout<<ans;
	return 0;
}
