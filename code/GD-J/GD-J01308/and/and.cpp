#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;	
int n,m,key,ans;
int dp[200005],a[200005];
bool co[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(co,0,sizeof(co));
		memset(dp,0,sizeof(dp));
		co[i]=1;
		dp[1]=a[i];
		for(int k = 2; k <= m; k++){
			key=0;
			for(int j = 1; j <= n; j++)
				if(!co[j] && dp[k]<dp[k-1]&a[j])
					dp[k]=dp[k-1]&a[j],key=k;
			if(key==0)
			{
				int dip=1;
				while(co[dip])
					dip++;
				key=dip;
				dp[k]=dp[k-1]&a[dip];
				for(int j = dip+1; j <= n; j++)
					if(!co[j] && dp[k]<dp[k-1]&a[j])
						dp[k]=dp[k-1]&a[j],key=k;
			}
			co[key]=1;
			cout<<key<<endl;
		}
		ans=max(ans,dp[m]);
	}
	cout<<ans;
	return 0; 
}
