#include<bits/stdc++.h>
using namespace std;
int a[500001],tj[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		tj[a[i]]=max(tj[a[i]],i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tj[i]<<" ";
	}
	return 0;
}
