#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
int a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("ans out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n;i>=(n-m+1);i--)
	{
		if(i==n)ans=a[i];
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
} 
