#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int b[100005];
	bool t[100005];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(t[a[i]]==true)
		{
			t[a[i]]=false;
			b[a[i]]=i;
		}
		else
		{
			for(int j=b[a[i]]+1;j<i;j++)
			{
				t[a[j]]=true;
			}
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 
