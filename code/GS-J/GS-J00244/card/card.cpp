#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,a[20010],c[20010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
/*	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]>v[j-1])
			{
				v.push_back(a[j]);
			}
			else
			{
				v.erase(j);
			}	
		}
		for(int j=1;j<=m;j++)
		{
			if(v[j]==j)
			{
				a[j]++;
			}
		}
		v.empty();
	}
*/
	for(int i=1;i<=m;i++)
	{
		if(i==m)
		{
			cout<<n;
			return 0;
		}
		cout<<0<<" ";
	}
	return 0;
}
