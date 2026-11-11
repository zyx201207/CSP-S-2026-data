#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],ans[400000],w;
int main()
{	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int p[600000],
		w=0;
		for(int j=i;j<=n;j++)
		{
			w++;
			if(p[a[j]]==0)
				p[a[j]]=w;
			else
			{
				int q=w;
				for(int k=p[a[j]];k<=q-1;k++)
				{	p[k]=0;w--;}
				p[a[j]]=w;
			}			
		}
		for(int j=i;j<=n;j++)
			if(p[a[j]]>0)
				ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)
				cout<<ans[i];
	return 0;
}
