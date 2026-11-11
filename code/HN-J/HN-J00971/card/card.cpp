#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],cnt[N];
map<int,int> mp;
vector<int> g[N];
bool f[N];
signed main()
{
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		stack<int> q;
		mp.clear();
		for(int i=1;i<=m;i++)
			f[i]=0;
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]==0)
			{
				mp[a[j]]++;
				q.push(a[j]);
			}
			else
			{
				while(!q.empty()&&q.top()!=a[j])
				{
					mp[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			f[q.top()]=1;
			q.pop();
		}
		for(int i=1;i<=m;i++)
			if(f[i])
			{
				cnt[i]++;
			}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
1 2 1 4

10 3
3 1 2 1 3 2 3 1 2 1
1 2 3 2 1 3 5 4 6 8
5 4 6 8 7 9 7 10 9 10
*/

