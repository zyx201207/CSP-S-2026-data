#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,a[200010],sum=INT_MAX,maxn=INT_MIN;
int csp=INT_MIN;
bool book[200010];
void dfs(int s,int cnt)
{
	if(s==m)
	{
		csp=max(csp,cnt);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!book[i])
		{
			book[i]=1;
			dfs(s+1,(cnt&a[i]));
			book[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum=sum&a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		cout<<sum;
		return 0;
	}
	dfs(0,INT_MAX);
	cout<<csp;
	return 0;
}
