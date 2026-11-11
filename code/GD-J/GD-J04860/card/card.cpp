#include<bits/stdc++.h>
using namespace std;
long long n,m,d[500005],a[300005],c[300005],b[300005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,1,sizeof(b));
		queue<long long> q;
		for(int j=1;j<=n;j++)
		{
			q.emplace(a[i]);
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(b[a[k]]>0)
					{
						b[a[k]]--; 
					}
				} 
				continue;
			}
			b[a[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(b[j]!=0)
			{
				d[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
