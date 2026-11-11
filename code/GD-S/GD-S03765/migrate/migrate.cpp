#include<bits/stdc++.h>
using namespace std;
constexpr int N=2e6+5;
int c,T;
int n,k,ans;
int a[N],s[N];
vector<int> vec[N];
bool bfs(int x,int y)
{
	queue<int> q;
	q.push(x);
	int res=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u>y) continue;
		for(int i:vec[s[u]+1])
		{
			if(a[i]-a[u]<=k) 
			{
				if(i==y) 
				{				
					++res;
					continue;
				}
				q.push(i);
			}
		}
	}
	return res==2;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);ans=0;
		for(int i=1;i<=n;i++)
		vec[i].clear();
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		vec[0].push_back(1);
		for(int i=2;i<=n;i++) 
		{
			int it=upper_bound(a+1,a+1+n,a[i]-k)-a;
			--it;
			s[i]=s[it]+1;
			vec[s[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(bfs(i,j)) ++ans; 
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
 
