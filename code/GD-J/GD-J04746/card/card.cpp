#include <bits/stdc++.h>
using namespace std;
int n,m,a[500002];
bool ad[500002];
int at[500002],as[500002],num[500002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)  cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		int tp=1;
		for (int j=i;j<=n;j++)
		{
			if (!ad[a[j]])
			{
				ad[a[j]]=1;
				at[a[j]]=tp;
				as[tp]=a[j];
				tp++;
			}
			else
			{
				tp=at[a[j]]+1;
			}
		}
		for (int j=1;j<tp;j++)
		{
			cout<<as[j]<<' ';
		}
		cout<<endl;
		for (int j=1;j<tp;j++)
		{
			num[as[j]]++;
		}
	}
	for (int i=1;i<=m;i++)  cout<<num[m]<<' ';
	return 0;
}
