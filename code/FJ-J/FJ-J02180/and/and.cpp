#include <bits/stdc++.h>
using namespace std;
long long n,m,t=0,k=0,a[202020],f[31][202020],kkk[202020]={0},z[31]={0},sum,ans=0,y[202020]={0};
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(k!=n)
	{
		t++;
		for(int i=1;i<=n;i++)
		{
			f[t][i]=a[i]%2;
			a[i]/=2;
			if(a[i]==0 && y[i]==0)
			{
				y[i]=1;
				k++;
			}
		}
	}
	k=t;
	for(;t>=1;t--)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[t][i]==1 && kkk[i]==0) sum++;
		}
		if(sum<m) continue;
		if(sum==m)
		{
			z[t]=1;
			if(t==1)
				for(int i=1;i<=n;i++)
					//if(kkk[i]==0 && f[t][i]==1) cout<<i<<endl;
			continue;
		}
		z[t]=1;
		for(int i=1;i<=n;i++)
			if(f[t][i]==0) kkk[i]=1;
	}
	for(int i=1;i<=k;i++)
	{
		ans+=z[i]*pow(2,i-1);
	}
	cout<<ans;
	return 0;
}