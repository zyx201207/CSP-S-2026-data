#include<bits/stdc++.h>
#define int long long 
#define rk(i,l,r) for(int i=l;i<=r;++i)
#define rp(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back 
using namespace std;
int c,t,n,d;
int a[1010],dp[1010][1010];
void sol()
{
	cin>>n>>d;int ans=0;
	rk(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rk(k,1,n)
	{
		dp[k][k]=1;
		rk(i,k,n)
		{
			rk(j,i+1,n)
			{
				if(abs(a[j]-a[i])<=d)dp[k][j]+=dp[k][i];
			}
		}
		rk(i,1,n)
		{
			if(dp[k][i]==2)ans++;
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)sol();
	return 0;
 } 
