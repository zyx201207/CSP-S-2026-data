#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,d;
int a[2000010];
int b[2000010];//出度 
int c[2000010];//入度 
int in,out;
bool f[2000010];
vector<int> g;
//void dfs(int x)
//{
//	if(f[x])
//		return;
//	for(auto xx : g[x])
//	{
//		f[xx]=1;
//		if(c[xx]==2)
//			cout<<1;
//		dfs(xx);
//	}
//}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		vector<int> g(n+1,0);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]>a[i]+d)
					break;
//				g[i].push_back(j);
				b[i]++;
				c[j]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(f,0,sizeof(f));
//			dfs(i);
		}
		cout<<0;
	}
	return 0;
}
