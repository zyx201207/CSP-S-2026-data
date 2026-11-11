#include<bits/stdc++.h> 
using namespace std;
long long c,t,n,d,x,a[2000005],cnt[2000005],v[2000005];
void dfs(int nw,int m)
{
	for(int i=nw+1;i<=x;i++)
	{
		if(a[i]-a[nw]<=d) 
		{
			if(m+1<cnt[i])
			{
				cnt[i]=m+1;
				v[i]=1;
			}
			else if(m+1==cnt[i]) v[i]++;
			dfs(i,m+1);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int ans=0;
		if(n<=3)
		{
			cout<<0<<endl;
			continue;
		}
		x=n;
		cin>>a[1];
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>d) x=i-1;
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=i;j<=x;j++) cnt[j]=0x3f3f3f;
			cnt[i]=0;
			dfs(i,0);
			for(int i=1;i<=x;i++)
			{
				if(v[i]==2) ans++;
			}
			for(int j=i;j<=x;j++) v[i]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}

