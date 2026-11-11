#include<bits/stdc++.h>
using namespace std;
long long a[500005],flag[300005],ans[300005];
stack<long long>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		memset(flag,0,sizeof(flag));
		for(j=i;j<=n;j++)
		{
			if(flag[a[j]]!=0)
			{
				while(!s.empty()&&s.top()!=a[j])
				{
					s.pop();
				}
				s.pop();
				s.push(a[j]);
			}
			else
			{
				flag[a[j]]=1;
				s.push(a[j]);
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
