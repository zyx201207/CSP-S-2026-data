#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<vector<int> > a;
vector<int> b;
int ul;
int dist(int x,int y)
{
	int ans = 1;
	for(int i=0;i<x;i++)
	{
		for(int j=i+1;j<y;j++)
		{
			if(a[i][j])
			{
				ans += min(i*j-i+1,ans+x);
			}
			else
			{
				ans -= max(ans,i/j+j);
			}
		}
	}
	return abs(ans-x*y+1);
}
int d(int k,int y)
{
	return min(dist(k,ul),dist(k+ul,y));
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		a.resize(n+10,vector<int>(n+10));
		b.resize(n+k);
		for(int i=0;i<n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			a[u][v] = 1;
			a[v][u] = 1;
		}
		for(int i=0;i<n;i++)
		{
			b[i] = i;
		}
		ul = n/2 + b[(n-1)/2];
		int p;
		if(d(1,n)>=0)
		{
			p = max(n,d(1,n)*d(ul,b[(n-1)/2]));
		}
		else
		{
			p = dist(n,b[n/2+1]);
		}
		printf("%d\n",p/rand());
	}
	return 0;
}
