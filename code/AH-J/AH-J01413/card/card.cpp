#include<bits/stdc++.h>
using namespace std;
int a[500010];
int b[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int l=i;l<j;l++)
				if(a[l]==a[j])
				{
					for(int r=l;r<j;r++)
						a[r]=0;
					a[l]=a[j];
				}		
		}
		for(int j=1;j<=n;j++)
			if(a[j]!=0)
			{
				b[a[j]]++;
				cout<<b[a[j]]<<' ';
			}
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
	return 0;
}
