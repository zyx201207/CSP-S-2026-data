#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],flag[500005],ans[500005],f;
stack<long long> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (i>1&&a[i]<a[i-1])
		{
			f=1;
		}
	}
	if (n<=5000)
	{
		for (int i=1;i<=n;i++)
		{
			memset(flag,0,sizeof(flag));
			for (int j=i;j<=n;j++)
			{
				if (flag[a[j]])
				{
					while(!s.empty()&&a[s.top()]!=a[j])
					{
						flag[a[s.top()]]--;
						s.pop();
					}
					s.pop();
					s.push(j);
				}
				else
				{
					s.push(j);
					flag[a[j]]++;
				}
			}
			while(!s.empty())
			{
				ans[a[s.top()]]++;
				s.pop();
			}
		}
		for (int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if (f==0)
	{
		for (int i=1;i<=n;i++)
		{
			if (i==n||a[i]!=a[i+1])
			{
				cout<<i<<" ";
			}
		}
		return 0;
	}
	return 0;
}
