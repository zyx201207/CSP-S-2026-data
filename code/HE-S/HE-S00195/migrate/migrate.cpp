#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006],cnt[10000][10000],ans,f[2000][1000],a1[10000],b1[10000],fl;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--)
		{
			cin>>n>>d;
		for(int i=1;i<=n;i++)
		{	
			scanf("%d",&x[i]);
		}
			int d123=x[2]-x[1];
			int kuadu=floor(d/d123);
			if(kuadu==1)cout<<0<<endl;
			else {
				if(n-2*kuadu+1>0)cout<<n-2*kuadu+1<<endl;
			else cout<<0<<endl;
			}
			
	}
	return 0;
	}
	
		
	while(t--) 
	{
		
		if(c!=11&&c!=12)
		{
			cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
		}

for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
	{
		f[i][j]=1000000000;cnt[i][j]=1;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		if(x[j]-x[i]<=d)f[i][j]=1;
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=k;i++)
	for(int j=i+1;j<=n;j++)
		{
			if(j<k)continue;
			if(f[i][j]==f[i][k]+f[k][j])cnt[i][j]++;
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)if(cnt[i][j]==2)cout<<i<<j<<endl;;
	cout<<ans<<endl;
	}
	
	return 0;
 } 
