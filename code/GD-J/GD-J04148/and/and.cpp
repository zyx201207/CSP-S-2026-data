#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool vis[200010];
int max_ans=-2100000000;
void find_ans(int x,int num_ans)
{
	if(x==m)
	{
		max_ans=max(max_ans,num_ans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(num_ans==0)
			{
				find_ans(x+1,a[i]);
			}
			else
			{
				find_ans(x+1,num_ans&a[i]);
			}
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	find_ans(0,0);
	cout<<max_ans;
}
