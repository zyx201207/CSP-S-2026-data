#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int long long
int a[500010];//mark little Z again.Don't play the Arcaea.
int ans[500010];
vector<int> q;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		q.clear();
		for(int j=i;j<=n;j++)
		{
			if(binary_search(q.begin(),q.end(),a[j]))
			{
				auto k=lower_bound(q.begin(),q.end(),a[j]);
				q.erase(k,q.end());
			}
				
			q.push_back(a[j]);
		}
		for(auto u:q) ans[u]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	//?
	return 0;
}
