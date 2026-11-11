#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],ans[500005],lst[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=1;
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		b[a[i]]=lst[a[i]];
	}
	for(int i=1;i<=n;i++)
	{
		c[b[a[i]]+1]+=c[i];
		ans[a[i]]+=c[i];
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m)
		{
			cout<<" ";
		}
	}
	return 0;
}
