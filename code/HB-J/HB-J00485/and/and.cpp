#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],book[200005],ans;
int n,m;
void dfs(int x,int idx)
{
	if(x==m+1||idx==n+1)
	{
		if(x<m)
		{
			return ;
		}
		int sum=b[1];
		for(int i=2;i<=m;i++)
		{
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return ;
	}
	if(book[idx]==0)
	{
		b[x]=a[idx];
		book[idx]=1;
		dfs(x+1,idx+1);
		book[idx]=0;
		b[x]=0;
	}
	dfs(x,idx+1);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(b,0,sizeof(b));
	memset(book,0,sizeof(book));
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
