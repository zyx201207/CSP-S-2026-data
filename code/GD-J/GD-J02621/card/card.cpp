#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long n,m,a[N],ans[M]={0};
bool vis[M]={false};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		stack<long long> s;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(s.top()!=a[j])
				{
					vis[s.top()]=false;
					s.pop();
				}
			}
			else
			{
				s.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			vis[s.top()]=false;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	return 0;
}
