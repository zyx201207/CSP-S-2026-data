#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t,c;
ll dp[5005]={},a[5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	// dijstra+dp
	cin>>c>>t;
	while(t--){
		ll n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int j;
			for(j=i+1;j<=n;j++)
			{
				dp[i]=1;
				for(int k=i+1;k<=j;k++){
					for(int x=k-1;a[k]-a[x]<d-1 && x>=i;x--)
					{
						dp[k]+=dp[x];
					}
				}
			}
			if(dp[j]==2) ans++;
			memset(dp,0,sizeof dp);
		}
		cout<<ans<<endl;
	}
	return 0;
}



