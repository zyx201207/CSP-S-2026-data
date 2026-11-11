#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,a[N],s;
ll ans;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int l=1,r=n;l<r;)
	{
		if(c[l]!=c[r])
			ans+=min(a[l],a[r]);
		s=min(a[l],a[r]);
		a[l]-=s;
		a[r]-=s;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans;
	return 0;
}
