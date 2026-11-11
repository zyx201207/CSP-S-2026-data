#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int mk[300010],ans[300010],ls[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int k=0;
	for(int i=n;i>=1;i--)
	{
		if(!mk[a[i]])
		{
			ls[a[i]]=i;
			mk[a[i]]=1;
			k++;
		}
		if(k==m)
		{
			break;
		}
	}
	int l=1;
	while(l<=n)
	{
		int k=l;
		while(k<=n)
		{
			k=ls[a[k]];
			ans[a[k]]++;
			k++;
		}
		l++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

