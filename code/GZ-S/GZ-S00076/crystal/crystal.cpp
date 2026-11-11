//GZ-S00076 ≥¬Û„„Â 
#include<bits/stdc++.h>
using namespace std;
const int N=1E5;
#define ull long long 
ull n,m,ans=0,ma,avg;
ull a[N],dp[N],an[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
	{
		avg=n/2;
	}
	else
	{
		avg=n/2+1; 
	}
	ma=a[avg];
	ull sce=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=abs(a[i]-ma);
	}
	sort(dp+1,dp+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==ma)
		{
			ans++;
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[i]!=0 and dp[i]<m)
		{
			cnt1=cnt1+1;
			cnt2+=dp[i]; 
		}
		if(cnt2==m or (cnt2<m and cnt2+dp[i+1]>m))
		{
			ans+=cnt1;
		}
	}
	cout<<ans;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
