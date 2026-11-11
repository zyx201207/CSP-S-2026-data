#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	if(n/2<=k)
	{
		if(n/2+1<=k)
		{
			cout<<"0\n";
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cid,T;
	cin>>cid>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
