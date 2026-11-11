#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],b[30005],v[50005],l;
queue<int>q;
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
		for(int j=i;j<=n;j++)
		{
			if(a[j]!=a[q.front()])
			{
				q.push(j);
				v[j]=1;
				l++;
			}
			else
			{
				while(l==0)
				{
					v[q.front()]=0;
					q.pop();
					l--;
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(v[j]==1)
			{
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
