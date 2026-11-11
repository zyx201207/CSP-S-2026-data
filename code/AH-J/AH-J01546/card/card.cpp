#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],ans[200005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int t[500005]={0},eeee=0,f[200005]={0};
		bool e[200005]={0};
		for(int j=i;j<=n;j++)
		{
			eeee++;
			if(f[a[j]]>=eeee||t[f[a[j]]]!=a[j])
			{
				e[a[j]]=0;
			}
			if(e[a[j]]==0)
			{
				e[a[j]]=1;
				t[eeee]=a[j];
				f[a[j]]=eeee;
			}
			else
			{
				eeee=f[a[j]];
			}
			
		}
		for(int j=1;j<=eeee;j++)
		ans[t[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
