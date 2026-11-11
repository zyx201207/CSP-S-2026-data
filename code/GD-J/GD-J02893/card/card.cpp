#include<bits/stdc++.h>
using namespace std;
int ans[200005],a[200005],fl[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		queue<int>q;
		for(int j=1;j<=m;j++)
			fl[j]=0;
		int xia=i;
		for(int j=i;j<=n;j++)
		{
			if(!fl[a[j]])
				fl[a[j]]=1;
			else
				xia=j;
		}
		for(int j=xia;j<=n;j++)
			ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0; 
} 
