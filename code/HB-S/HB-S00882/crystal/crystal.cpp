#include<bits/stdc++.h>
using namespace std;
long long a[500005],dp[500005];
long long n,m;
long long num=0,ans=1;
long long maxn=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(long long k=1;k<=n;k++){
		memset(dp,0,sizeof(dp));
		for(long long i=k;i<=n;i++)
		{
			int nnn=0;
			if(a[i]==a[i+1])
			{
				ans++;
			}
			if(i==n){
				maxn=max(maxn,ans);
				ans=1;
			}
			else if(a[i]!=a[i+1]){
				num=abs(a[i+1]-a[i]);
				dp[i+1]=dp[i]+i*num;
				nnn=1;
			}
			if(dp[i+1]>m){
				maxn=max(maxn,ans);
				ans=1;
				break;
			}
			if(nnn==1){
				ans++;
			}
			
		}
	}
	cout<<maxn<<endl;
	return 0;
}


