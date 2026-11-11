#include<bits/stdc++.h>
using namespace std;
int a[400005];
int js[400005];
int lll[400005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	const int po=n;
	int x=0;
	while(n--)
	{
		unsigned int p=0;
		for(int i=x;i<po;i++)
		{
			int ll=a[i];
			for(int j=x;j<p;j++)
			{
				if(lll[i]==ll)
				{
					p=j-1;
				}
			}
			lll[p]=ll;
			p++;
		}
		for(int i=x;i<p;i++)
		{
			js[lll[i]]++;
		}
		x++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<js[i]<<" ";
	}
	return 0;
}
