#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000005];
queue<int>q;
vector<int>e[100005];
void bfs(int o,int p)
{
	int cnt=0;
	q.push(o);
	book[o]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<e[o].size();i++)
		{
			int u=e[o][i];
			if(book[u]==1) continue;
			
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			if(abs(a[i]-a[i-1])<=d)
			{
				e[a[i]].push_back(a[i-1]);
				e[a[i-1]].push_back(a[i]);
			}
		}
		sort(a+1,a+1+n);
		for(int i=1;i<n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				bfs(a[i],a[j]);
			}
		}
	}
	return 0;
}
