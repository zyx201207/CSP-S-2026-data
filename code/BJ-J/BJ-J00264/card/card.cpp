#include<bits/stdc++.h>
using namespace std;
bitset<500005> flag;
int n,m;
int cnt[300005],a[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int rnd=1;rnd<=n;rnd++)
	{
		flag.reset();
		stack<int> s;
		for(int i=rnd;i<=n;i++)
		{
			if(!flag[a[i]])
			{
				s.push(a[i]);
				flag[a[i]]=true;
			}
			else
			{
				while(s.top()!=a[i] && !s.empty())
				{
					flag[s.top()]=false;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
