#include<bits/stdc++.h>
using namespace std;
int c,t,n;long long d,x[2000001],f[5001][5001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<n;i++)
			if(x[i+1]-x[i]<=d)
				f[i][i+1]=1;
		for(int i=2;i<n;i++)
			for(int j=1;j+i<=n;j++)
				for(int k=j+1;k<j+i;k++)
					if(x[k]-x[j]<=d&&x[j+i]-x[k]<=d)
						f[j][j+i]=f[j][j+i]+f[j][k]*f[k][j+i];
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(f[i][j]==2&&x[j]-x[i]>d)
					ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
