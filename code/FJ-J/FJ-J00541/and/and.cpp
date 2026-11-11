#include <iostream>
using namespace std;
int n,m,flag[200005];
long long num[200005],lastans=-1;
void dfs(int u)
{
	if(u==m+1)
	{
		int pos=0;
		long long first=0;
		for (int i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				pos=i;
				first=num[i];
				break;
			}
		}
		for (int i=pos+1;i<=n;i++)
			if(!flag[i]) 
				first&=num[i];
		lastans=max(first,lastans);
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=1;
			dfs(u+1);
			flag[i]=0;
			dfs(u+1);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>num[i];
	for (int i=1;i<=n;i++) flag[i]=0;
	dfs(1);
	cout<<lastans;
	return 0;
}
