#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[500005],cnt[300005],ans[300005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int>st;
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]])
			{
				while(st.top()!=a[j])
				{
					cnt[st.top()]--;
					st.pop();
				}
				cnt[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			cnt[a[j]]++;
		}
		while(st.size())
		{
			ans[st.top()]++;
			cnt[st.top()]--;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
