#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long q,c,n,a[20002],i,j,k,d,ke[20002],ans=0,jie[20002],len=0;
	cin>>c>>q;
	while(q--)
	{
		len=ans=0;
		memset(ke,0,sizeof(ke));
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>=d)jie[++len]=i;
		}
		jie[++len]=n+1;
		jie[0]=1;
		for(k=1;k<=len;k++)
			for(i=jie[k-1];i<jie[k]-3;i++)
				for(j=i+3;j<jie[k];j++)
					if((j-i-2)*d<a[j]-a[i]&&a[j]-a[i]<(j-i-1)*d)
						ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
