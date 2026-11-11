#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		ans=max(ans,x);
		}
		cout<<ans;
	return 0;
}
