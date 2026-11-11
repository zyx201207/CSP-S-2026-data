#include<bits/stdc++.h>

using namespace std;

int n,m,a[500010],b[300010];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int> q,p;
		for(int j=i;j<=n;j++)
		{
			while(q.size()&&q.back()!=a[j])q.pop_back();
			if(q.size())q.pop_back();
			q.push_back(a[j]);
		}
		for(int x:q)
		{
			b[x]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
