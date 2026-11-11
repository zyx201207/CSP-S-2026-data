#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e5+5; 
ll n,m,a[maxn];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	ll ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		ans=(ans&a[i]);
	}
	cout<<ans;
	
	return 0;
}
//Trick||Treat!
