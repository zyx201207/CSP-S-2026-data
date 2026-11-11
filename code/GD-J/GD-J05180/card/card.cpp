#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
bool book[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		stack<int>q;
		memset(book,0,sizeof(book));
		for(int i=j;i<=n;i++)
		{
			if(book[a[i]])
			{
				while(!q.empty()&&q.top()!=a[i])
				{
					book[q.top()]=0;
					q.pop();
				}
			}
			book[a[i]]=1;
			q.push(a[i]);
		}
		for(int i=1;i<=m;i++)
		{
			if(book[i])ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
