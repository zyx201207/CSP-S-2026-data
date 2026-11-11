#include  <bits/stdc++.h>
using namespace std;
int n,m,top;
int a[500005],book[300005],s[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m ;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=0;k<=top;k++)
			{
				if(s[k]==a[j])
				{
					top=k-1;
					break;
				}
			}
			s[++top]=a[j];
		}
		for(int j=1;j<=top;j++)
		{
			book[s[j]]++;
		}
		top=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout << book[i] << " " ;
	}
	return 0;
}
