#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],ans[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j;i<=n;i++)
		{
			ans[a[i]]++;
			if(i!=b[a[i]]) i=b[a[i]];
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
