#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],f[100000],t,ans[100000],b[100000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
			f[j]=0;
		t=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1)
				while(b[t]!=a[j])
					t--;
			else
				b[++t]=a[j];
			f[a[j]]=1;
		}
		for(int i=1;i<=t;i++)
			ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
