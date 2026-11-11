#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define PII pair<int,int>
//#define fi first
//#define se second
const int N=2e6+10;
int a[N],L[N],R[N];
int dp[N][2],s[N][2];
void solve()
{
	int n,m;cin>>n>>m;
	for(int i=0;i<=n+1;i++)dp[i][0]=dp[i][1]=s[i][0]=s[i][1]=L[i]=R[i]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,l=1;i<=n;i++)
	{
		while(l<i&&a[i]-a[l]>m)l++;
		L[i]=l;
	}
	for(int i=n,r=n;i>=1;i--)
	{
		while(r>i&&a[r]-a[i]>m)r--;
		R[i]=r;
	}
//	for(int i=1;i<=n;i++)cout<<L[i]<<' ';cout<<'\n';
//	for(int i=1;i<=n;i++)cout<<R[i]<<' ';cout<<'\n';
	for(int i=1;i<=n;i++)
	{
//		int pl=lower_bound(R+1,R+n+1,L[i])-R,pr=upper_bound(R+1,R+n+1,L[i])-R-1;
//		cout<<i<<' '<<pl<<' '<<pr<<'\n';
//		if(R[L[i]]==i)dp[i][0]+=dp[L[i]][0];
//		cout<<dp[i][0]<<'\n';
		if(L[i]!=i)
		{
			int pl=lower_bound(R+1,R+n+1,i)-R,pr=upper_bound(R+1,R+n+1,i)-R-1;
//			pr=min(pr,i-1);
			if(pr==i)pr=i-1;
			if((pr==i-1||R[i-1]<R[i]-1)&&pl<=pr)dp[i][0]+=s[pr][0]-s[pl-1][0];
		}
		dp[i][0]++;
		s[i][0]=s[i-1][0]+dp[i][0];
	}
	for(int i=n;i>=1;i--)
	{
//		int pl=lower_bound(L+1,L+n+1,R[i])-L,pr=upper_bound(L+1,L+n+1,R[i])-L-1;
//		cout<<i<<' '<<pl<<' '<<pr<<'\n';
//		if(L[R[i]]==i)dp[i][1]+=dp[R[i]][1];
		if(R[i]!=i)
		{
			int pl=lower_bound(L+1,L+n+1,i)-L,pr=upper_bound(L+1,L+n+1,i)-L-1;
//			pl=max(pl,i+1);
			if(pl==i)pl=i+1;
			if((pl==i+1||L[i+1]>L[i]+1)&&pl<=pr)dp[i][1]+=s[pl][1]-s[pr+1][1];
		}
		dp[i][1]++;
		s[i][1]=s[i+1][1]+dp[i][1];
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(L[i]+1<i)
	{
		int pl=lower_bound(R+1,R+n+1,L[i]+1)-R,pr=upper_bound(R+1,R+n+1,L[i]+1)-R-1;
//		cout<<i<<' '<<pl<<' '<<pr<<'\n';
		if(pl<=pr)ans+=(s[pr][0]-s[pl-1][0])*dp[i][1];
//		cout<<(s[pr][0]-s[pl-1][0])<<' '<<dp[i][1]<<'\n';
	}
//	for(int i=1;i<=n;i++)cout<<dp[i][0]<<' ';cout<<'\n';
//	for(int i=1;i<=n;i++)cout<<dp[i][1]<<' ';cout<<'\n';
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
9 9
3 8 10 13 15 20 21 24 31 
*/
