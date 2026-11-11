#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int n,m;
int mp[N];
int maxx=0;
vector<int> e[N]; 
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			mp[abs(a-b)]++;
			maxx=max(maxx,abs(a-b));
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int ans=0;
		for(int i=1;i<=maxx;i++) ans=max(ans,mp[i]);
		cout<<ans<<'\n';
	}
	return 0;
}
