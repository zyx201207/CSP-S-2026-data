#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],h[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)//第i局
	{
		stack<int> st,st1;
		map<int,int> mp;
		for(int j=i;j<=n;j++)
		{
			if(!mp.count(a[j]))
			{
				mp[a[j]]++,st.push(a[j]);
				continue;
			}
			while(!st.empty())
			{
				int u=st.top();
				st.pop();
				if(u==a[j]) break;
			}
			mp.clear();
			while(!st.empty())
			{
				int u=st.top();
				st.pop();
				st1.push(u);
				mp[u]++;
			}
			while(!st1.empty())
			{
				int u=st1.top();
				st1.pop();
				st.push(u);
			}
			mp[a[j]]++,st.push(a[j]);
		}
		while(!st.empty())
		{
			int u=st.top();
			st.pop();
			h[u]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<h[i]<<" ";
	return 0;
}
