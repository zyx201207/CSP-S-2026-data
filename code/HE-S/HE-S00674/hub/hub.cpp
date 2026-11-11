#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+50;
int u[N],v[N];
inline void solve()
{
	int n,k;
	for(int i=1;i<n;++i)
	{
		cin>>u[i]>>v[i];
	}
	for(int i=1;i<=n;++i)
	{
		cout<<i<<endl;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int T,c;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
