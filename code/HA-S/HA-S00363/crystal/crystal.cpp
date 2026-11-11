#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(1ll*(i-l+1)*a[i]-(s[i]-s[l-1])>m) l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
