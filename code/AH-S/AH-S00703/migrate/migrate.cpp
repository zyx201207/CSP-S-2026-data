#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000001],kt[5001],dp[5001],g[5001],la[5001],s[5001],zy[5001];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		if(n==1)
		{
			int x;
			cin>>x;
			cout<<"0\n";
			continue;
		}
		if(c==11||c==12)
		{
			for(int i=1;i<=n;i++)
				cin>>a[i];
			int e=d/(a[2]-a[1]),s=max(0LL,n-(e+e-1));
			if(e<=1)
				cout<<"0\n";
			else
				cout<<s<<"\n";
			continue;
		}
		if(c==13||c==14)
		{
			for(int i=1;i<=n;i++)
				cin>>a[i];
			for(int i=1;i<=n;i++)
				zy[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			int s=0;
			for(int i=1;i<=n;i++)
			{
				int ne1=zy[i]-1,ne2=zy[i]-2,d1=zy[ne1],d2=zy[ne2];
				if(ne1==i)
					continue;
				s+=d1-d2;
			}
			cout<<s<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=i;j>=1;j--)
			{
				if(a[i]-a[j]>d)
					break;
				kt[i]=j;
			}
		}
		int ss=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=0,g[i]=1,s[i]=1,s[i-1]=0,la[0]=i;
			for(int j=i+1;j<=n;j++)
			{
				if(kt[j]==j)
					continue;
				int z=max(kt[j],i);
				dp[j]=dp[z]+1,la[dp[j]]=j,g[j]=s[la[dp[z]]]-s[z-1],s[j]=s[j-1]+g[j],ss+=(g[j]==2);
			}
		}
		cout<<ss<<"\n";
	}
	return 0;
}
