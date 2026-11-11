#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d,l[5005],dp1[5005][5005],dp2[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&l[i]);
		for(int i=1,j=1;i<=n;i++)
		{
			while(j<i&&l[i]-l[j]>d) j++;
			for(int p=j;p<i;p++) dp1[p][i]=dp2[p][i]=1;
			for(int p=1;p<j;p++)
			{
				dp1[p][i]=LONG_LONG_MAX;
				for(int q=j;q<i;q++)
					dp1[p][i]=min(dp1[p][i],dp1[p][q]+1);
				for(int q=j;q<i;q++)
					dp2[p][i]+=dp1[p][q]+1==dp1[p][i]?dp2[p][q]:0;
				if(dp2[p][i]==2)
				{
					//cout<<p<<' '<<i<<endl;
					ans++;
				}
				//if(p==1&&i==4) cout<<dp1[p][i]<<' '<<dp2[p][i]<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
