#include<bits/stdc++.h>
using namespace std;
int a[600000],c[400000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		vector<int>b;
		int b1=1;
		for(int j=i;j<=n;j++)
		{
			bool flag=1;
			for(int k=1;k<=b.size();k++)
			{
				if(a[j]=b[k])
				{
					b1-=(b.size()-k-1);
					flag=0;
					continue;
				}
			}
			if(flag)
			{
				b[b1]=a[j];
				b1++;
			}
		}
		for(int j=1;j<=b1;j++)
		{
			for(int k=1;k<=m;k++)
			{
				if(b[j]==k)
				{
					c[k]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<rand();
	return 0;
}
