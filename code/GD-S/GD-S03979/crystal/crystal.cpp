#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;

int n;
ll m,a[N],pre[N],suf[N];

bool check(int len)
{
	for(int l=1;l+len-1<=n;l++)
	{
		int r=l+len-1;
		int mid=r;
		ll A=pre[mid]-pre[l]-1ll*(l-1)*(a[mid]-a[l]);	
		if(A<=m) 
		{
			return true;
		}
	}return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+1ll*(i-1)*(a[i]-a[i-1]);
	}

	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
