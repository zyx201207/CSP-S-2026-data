#include<bits/stdc++.h>
using namespace std;
int const N=1e6;
int s[N],n,m,maxn=INT_MIN;
bool vis[N];
int h(int n,int m)
{
	int len,sum=0;
	vector<int> s1,s2;
	while(n)
	{
		s1.push_back(n%2);
		n=n/2;
	}
	while(m)
	{
		s2.push_back(m%2);
		m=m/2;
	}
	len=min(s1.size(),s2.size());
	for(int i=0;i<=len-1;i++)
	{
		if(s1[i]==s2[i]&&s1[i]==1) sum=sum+pow(2,i);
	}
	return sum;
}
void dfs(int tot,int ans)
{
	if(tot==m)
	{
		maxn=max(maxn,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(h(ans,s[i])>=maxn)
			{
				vis[i]=1;
				dfs(tot+1,h(ans,s[i]));
				vis[i]=0;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(1,s[i]);
		vis[i]=0;
	}
	printf("%d",maxn);
	return 0;
}
