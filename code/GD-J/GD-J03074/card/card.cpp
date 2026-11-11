#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn];
long long ans[maxn];
bool flag[maxn];
stack<int>s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(flag,false,sizeof(flag));
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				while(!s.empty()&&s.top()!=a[j])
				{
					flag[s.top()]=false;
					s.pop();
				}
			}
			else
			{
				s.push(a[j]);
				flag[a[j]]=true;
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
