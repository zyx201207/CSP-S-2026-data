#include<bits/stdc++.h>
#define ll long long
using namespace std;
int m,n;
ll a[200050],ans=0;
bool b[200050]={0};
void dfs(int x,ll y)
{
	if(x>m)
	{
		ans=max(ans,y);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			dfs(x+1,y&a[i]);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","c",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		b[j]=1;
		dfs(2,a[j]);
	}
	cout<<ans;
	return 0;
}
