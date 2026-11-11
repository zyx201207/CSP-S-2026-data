#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> a;
vector<vector<int> > t;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	a.resize(m);
	t.resize(n+1,vector<int>(n+1));
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
	vector<int> xd;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		xd.push_back(x);
		for(int j=0;j<x;j++)
		{
			int g,h;
			scanf("%d %d",&g,&h);
			t[i][g] = h;
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		long long p = a[x]+a[y];
		for(int j=0;j<x;j++)
		{
			for(int k=j;k<y;k++)
			{
				p += t[j][k];
			}
		}
		printf("%d\n",p+rand());
	}
	return 0;
}
