#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
int arr[N],g[N],st[N];
int max_sum=-1e9;
int n,m;
int dfs(int step)
{
	if(step==m+1)
	{
		int sum=g[1];
		for(int i=2;i<=m;i++)
		{
			sum=sum&g[i];
		}
		max_sum=max(sum,max_sum);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(st[i]==0)
			{
				st[i]=1;
				g[step]=arr[i];
				dfs(step+1);
				st[i]=0;
			}
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	dfs(1);
	cout << max_sum;
	return 0;
} 
