#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],pre[2000005],nex[2000005],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int las=1,s1,s2,a;
		for(int i=2;i<=n;i++)
		{
			while(x[i]-x[las]>d)las++;
			pre[i]=las;
		}
		las=n;ans=0;
		for(int i=n-1;i>=1;i--)
		{
			while(x[las]-x[i]>d)las--;
			nex[i]=las;
		}
		for(int i=4;i<=n;i++)
		{
			if(pre[i]+1>=i||pre[i]==1||pre[i]==i)continue;
			a=pre[pre[i]+1];
			if(nex[a]!=pre[i]+1)continue;
			s1=pre[pre[i]+2]-a,s2=1;
			if(a>1&&pre[pre[i]]==a&&pre[a]!=a)
			{
				while(a>1&&pre[a]<a&&nex[pre[a]]==a)
				{
					s1+=pre[a+1]-pre[a];
					a=pre[a];
				}
			}
			if(i<n&&nex[nex[pre[pre[i]]]]==i&&nex[i]!=i&&nex[pre[i]]==i)
			{
				a=i;
				while(a<n&&nex[a]>a&&pre[nex[a]]==a)
				{
					s2+=nex[a]-nex[a-1];
					a=nex[a];
				}
			}
			ans+=s1*s2;
//			cout<<i<<' '<<s1<<' '<<s2<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
