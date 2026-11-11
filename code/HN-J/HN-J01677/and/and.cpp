#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int m;
struct node
{
	bool vis[N];
	int x;
}mx[N];
int n,a[N];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx[i].x=a[i];
	}
	m-=1;
	while(m--)
	{
		for(int i=1;i<=n;i++)
		{
			int maxn=0;
			int hm;
			for(int j=1;j<=n;j++)
			{
				
				if(i!=j&&!mx[i].vis[j])
				{
					int u=a[j];
					u&=mx[i].x;
					if(maxn<u)
					{
						maxn=u;
						hm=j;
					}
				}
			}
			//cout<<i<<' '<<a[i]<<' '<<maxn<<' '<<a[hm]<<'\n';
			mx[i].vis[hm]=1;
			mx[i].x=maxn;
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<mx[i].x<<' ';
		maxn=max(maxn,mx[i].x);
	}
	cout<<maxn;
	return 0;
}
