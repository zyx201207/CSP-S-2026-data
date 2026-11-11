#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans,t;
int maxn=INT_MIN;
int book[200005];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x)
{
	if(x==m+1)
	{
		maxn=max(maxn,ans);
		//cout<<ans<<" ";
		return;
	}
	if(ans==0 && maxn>=0)
		return;
	for(int i=1;i<=n;i++)
		if(book[i]==0)
		{
			//cout<<a[i]<<" ";
			t=ans;
			ans=ans&a[i];
			book[i]=1;
			dfs(x+1);
			book[i]=0;
			ans=t;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof(book));
		ans=a[i];
		book[i]=1;
		dfs(2);
	}
	cout<<maxn;
	return 0;
}
