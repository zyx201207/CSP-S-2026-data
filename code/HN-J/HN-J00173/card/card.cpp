#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		stack<int> s;
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==1)
			{
				while(s.top()!=a[j])
				{
					t[s.top()]=0;
					s.pop();
				}
			}
			else
			{
				s.push(a[j]);
				t[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=t[j];
		}
		memset(t,0,sizeof(t));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
