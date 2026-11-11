#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],f[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0]=0xfffffffff;
	if(m==n-1&&n>2000)
	{
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]&a[i];
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,(f[n]&a[i]));
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			f[j]=max(f[j],f[j-1]&a[i]);
	cout<<f[m];
}
