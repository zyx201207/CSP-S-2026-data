#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],i,j;
bool flag;
map<long long,long long>mp,vis; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i-1]>a[i])flag=1;
	}
	if(!flag)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]!=a[i+1])
			mp[a[i]]+=i;
		}
		for(i=1;i<=m;i++)
		printf("%lld ",mp[i]);
	}
	else
	{
	
		for(i=1;i<=n;i++)
		{
			vis.clear();
			deque<long long>q;
			for(j=i;j<=n;j++)
			{
				vis[a[j]]++;
				if(vis[a[j]]==1)
				q.push_back(j);
				else
				{
					while(!q.empty()&&a[q.back()]!=a[j])
					{
						vis[a[q.back()]]--;
						q.pop_back();
					}
					vis[a[q.back()]]--;
				}
			}
			while(!q.empty())
			{
				mp[a[q.back()]]++;
				//cout<<q.back()<<" ";
				q.pop_back();
			}
		}
		//cout<<"\n";
		for(i=1;i<=m;i++)
		printf("%lld ",mp[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/


