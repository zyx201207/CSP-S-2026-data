#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tot[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>0;j--)
		{
			if(tot[a[j]]==0)	break;
			ans[a[j]]++;
			if(tot[a[j]]>1)
			{
				break;
			}
		}
		tot[a[i]]--;
		a[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
	return 0;
}