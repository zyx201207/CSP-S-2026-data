#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=2e5+10;
int n,m,a[N],cnt=1;
set<int> s;
map<int,int> mp;
deque<int> q; 
signed main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		s.clear();
		for (int j=cnt;j<=n;j++)
		{
			if (s.count(a[j])>0) //³öÏÖ¹ý 
			{
				while (!q.empty()&&q.back()!=a[j]) 
				{
					s.erase(q.back());
					q.pop_back();
				}
				if (!q.empty())q.pop_back();
			} 
			s.insert(a[j]);
			q.push_back(a[j]);
		}
		while (!q.empty()) 
		{
			mp[q.front()]++;
			q.pop_front();
		} 
		cnt++;
	}
	for (int i=1;i<=m;i++) cout<<mp[i]<<" ";
	return 0;	
} 
