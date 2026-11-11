#include<bits/stdc++.h>
using namespace std;
int a[5000010],b[5000010],c[5000010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]=1;
		if(b[a[i]]==1)
		{
			for(int j=b[a[i]];j<=n;j++)
			{
				b[i]=0;
			}
		}
		if(b[i]==1)
		{
			c[b[i]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[i];
	}
	return 0;
}
	
