#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int n,m,ans;
int a[N];
bool used[35];
vector<int> G;


signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		G.push_back(a[i]);
	}
	for(int j=30;j>=0;j--)
	{
		int cnt = 0, p = (1<<j);
		queue<int> q;
		for(int v : G)
		{
			if((v / p) % 2 == 1)
			{
				cnt++;
				q.push(v);
			}
		}
		if(cnt < m) continue;
		used[j] = true;
		G.clear();
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			G.push_back(u);
		}
	}
	
	for(int i=0; i<=30; i++)
	{
		ans+=(1<<i)*used[i];
	}
	cout<<ans;
	return 0;
}
