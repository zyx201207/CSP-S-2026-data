#include <bits/stdc++.h>
using namespace std;
long long n,m,t,a[505050],k[505050],f[303030],r[303030]={0};
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		t=0;
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==1)
			{
				while(k[t]!=a[j])
				{
					f[k[t]]=0;
					t--;
				}
				continue;
			}
			k[++t]=a[j];
			f[a[j]]=1;
		}
		for(int j=1;j<=t;j++)
			r[k[t]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<r[i]<<" ";
	return 0;
}