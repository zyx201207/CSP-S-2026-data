#include<iostream>
#include<bits/stdc++.h> 
#include<stack>
using namespace std;

bool flag[300005];
int ans[300005];
int a[500000];
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		stack<int>s;
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]]==1)
			{
				int now;
				do
				{
					now=s.top();
					flag[now]=0;
					s.pop();
				}
				while(now!=a[j]);
			}
			s.push(a[j]);
			flag[a[j]]=1;
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();

		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
