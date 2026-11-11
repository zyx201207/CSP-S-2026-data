#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int a[1000005];
map<int,bool>mp;
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int n,m;cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int q = 1; q <= n; q++)
	{
		mp.clear();
		for (int i = q; i <= n; i++)
		{
			if (mp[a[i]] == 0)
			{
				st.push(a[i]);
				mp[a[i]] = 1;
			}
			else
			{
				while(st.top() != a[i])
				{
					mp[st.top()] = 0;
					st.pop();
				}
			}
		}
		while(st.size()!=0)
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i =1; i <= m; i++) cout << ans[i] << " ";
	return 0;
 } 
