#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N],ans;
pair<int,int> p[N];
queue<int> q; 
void bfs(int x)
{
	q.push(x);
	p[x].second=1;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i=f+1;i<=n;i++)
		{
			if(a[i]-a[f]>d) break;
			if(!p[i].first)
			{
				q.push(i);
				p[i].first=p[f].first+1,p[i].second=p[f].second;
			}
			else
			{
				if(p[i].first==p[f].first+1) p[i].second++;
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(p[j].second==2) 
				{
					ans++;
				}
				p[j].first=0,p[j].second=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
