#include<bits/stdc++.h>
using namespace std;
const int N=500100;
typedef long long ll;
ll n,m,a[N],f[N];
bool check(ll mid)
{
	for(int i=1;i<=n-mid+1;i++)
	{
		ll sum=0;
		for(int l=i,r=i+mid-1;l<=r;l++)
		{
			sum+=a[r]-a[l];
		}
//		cout<<sum<<' ';
		if(sum<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	bool f=0;
	for(int i=1;i<=n;i++) if(a[i]!=i) f=1;
	if(!f)
	{
		int i=1;
		for(;m>=i;i++) m-=i;
		cout<<i;
		return 0;
	}
	f=0;
	for(int i=1;i<n;i++) if(a[i+1]-a[i]!=a[i+2]-a[i+1]) f=1;
	if(!f)
	{
		m=m/(a[2]-a[1]);
		int i=1;
		for(;m>=i;i++) m-=i;
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	ll l=1,r=n,s=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))
		{
			s=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
//		cout<<endl;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
