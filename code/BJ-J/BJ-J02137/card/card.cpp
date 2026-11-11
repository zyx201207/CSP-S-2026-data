#include <bits/stdc++.h>
using namespace std;
int a[500005],zhuo[500005],n,m;
int bo[300005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int bo1[300005];
		for(int k=0;k<=m;k++) bo1[k]=0;
		for(int j=i;j<n;j++)
		{
			if(bo1[a[j]]!=0)
			{
				for(int k=0;k<=m;k++) bo1[k]=0;
				bo1[a[j]]++;
			}
			else
			{
				bo1[a[j]]++;
			}
		}
		for(int k=0;k<=m;k++) bo[k]+=bo1[k];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<bo[i]<<' ';
	}
}
