#include<bits/stdc++.h>
using namespace std;
vector<long long> b[5000005];
queue<long long> qx;
struct Node
{
	long long a,b;
};
map<long,long> mp[1000005];
long long a[5000005],f[5000005],d,cnt,ans,n,d;
void bfs(long long x,int y)
{
	cnt=0;
	qx.push(x);
	f[x]=1;
	while(!qx,empty())
	{
		cnt++;
		long long t=qx.top();
		int tx=lower_bound(a+1,a+n+1,t)-a;
		mp[tx][cnt]++;
		for(int i=1;i<=b[t].size();i++)
		{
			if(f[b[t][i]]==0)
			{
				qx.push(b[t][i]);
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.in","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int pos=i;
			while(a[i]+d>a[pos])
			{
				b[a[i]].push_back(a[pos]);
				pos++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(a[i],i);
			for(int j=i+1;j<=n;j++)
			{
				auto it=mp[j].begin();
				if(it->second==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
