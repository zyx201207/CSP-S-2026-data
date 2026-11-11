#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v,now;
int n,m,a,ans;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a,v.push_back(a);
	for(int i=30;i>=0;i--)
	{
		now.clear();
		for(auto j:v)if((j>>i)&1)now.push_back(j);	
		if((int)now.size()>=m)
		{
			ans+=(1ll<<i);
			v=now;
		}
	} 
	cout<<ans;
	return 0;
}

