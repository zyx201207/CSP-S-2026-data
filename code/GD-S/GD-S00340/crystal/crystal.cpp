#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans,f[500001],p=1,q=1,d[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	for(int i=2;i<=n;i++) f[i]=f[i-1]+(a[i]-a[i-1])*(i-1);
	while(q<=n)
	{
		long long sum=f[q]+d[p-1]-a[q]*(p-1);
		if(sum<=m) {ans=max(ans,q-p+1);q++;}
		else p++;
	}
	cout<<ans;
	return 0;
}
