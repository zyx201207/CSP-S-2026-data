#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ar[500005],ar2[300005],ar3[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int a = 1;
	for(int i = 0;i<n;i++)
	{
		cin>>ar[i];
	}
	for(int i = 1;i<=300000;i++) ar2[i] = -1;
	for(int i = 0;i<n;i++)
	{
		if(ar2[ar[i]]!=-1)
		{
			for(int j = ar2[ar[i]];j<i;j++)
			{
				ar2[ar[j]] = max(n-ar2[ar[i]],ar2[ar[i]]);
			}
		}
		ar2[ar[i]] = i;
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ar2[i]+1<<' ';
	}
	return 0;
}
