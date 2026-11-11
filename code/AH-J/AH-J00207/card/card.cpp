#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010];
bool f[300010];
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
	for(int w=1;w<=n;w++)
	{
		memset(f,0,sizeof(f));
		stack<int> v;
		for(int i=w;i<=n;i++)
		{
			if(f[a[i]]==0)
			{
				v.push(a[i]);
				f[a[i]]=1;
			}
			else
			{
				while(!v.empty()&&v.top()!=a[i])
				{
					f[v.top()]=0;
					v.pop();
				}
			}
		}
		while(!v.empty())
		{
			cnt[v.top()]++;
			v.pop();
		}	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
