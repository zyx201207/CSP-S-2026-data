#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
const int INF=-1e12;
int n,m;
int a[N],b[N],dp[2][N],f[N];
int ans=0;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){b[i]+=b[i-1];}

	for(int i=1;i<=n;i++)dp[i][1]=a[i]+m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)if(dp[(i-1)%2][j]>=a[i])dp[(i)%2][j+1]=(dp[(i-1)%2][j]+a[i])/2,ans=max(ans,j+1);
	}
	

	cout<<ans;
	return 0;
	
} 
