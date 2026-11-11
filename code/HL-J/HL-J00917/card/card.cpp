#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005];
map <int,bool> mp;
stack <int> st;
inline void run(int x)
{
	mp.clear();
	for(int i=x;i<=n;i++)
	{
		if(!mp[a[i]])
		{
			st.push(a[i]);
			mp[a[i]] = 1;
		}
		else
		{
			while(st.size() && st.top() != a[i])
			{
				mp[st.top()] = 0;
				st.pop();
			}
		}
	}
	while(st.size())
	{
		ans[st.top()]++;
		st.pop();
	}
	return;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) run(i);
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}