# include <bits/stdc++.h>
# define N 2000010
# define int long long
using namespace std;
int c,t,n,d,a[N],f[N],dp[N],sum[N];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--) {
	  cin>>n>>d; int ans=0;
	  for(int i=1;i<=n;i++) cin>>a[i];
	  int l=1;
	  for(int i=1;i<=n;i++) {
	    while(a[i]-a[l]>d&&l<=i) l++;
	    f[i]=l;
	  }
	  for(int i=1;i<=n;i++) {
	    memset(dp,0x3f,sizeof(dp));
	    memset(sum,0,sizeof(sum));
	    dp[i]=0,sum[i]=1;
	    for(int j=i+1;j<=n;j++) {
	      for(int k=max(i,f[j]);k<j;k++) {
	        if(dp[k]+1<dp[j]) dp[j]=dp[k]+1,sum[j]=sum[k];
	        else if(dp[k]+1==dp[j]) sum[j]+=sum[k];
		  }
//		  cout<<i<<" "<<j<<" "<<sum[j]<<endl;
		  if(sum[j]==2) ans++;
		}
	  }
	  cout<<ans<<'\n';
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6

