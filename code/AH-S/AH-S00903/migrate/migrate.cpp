#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans,a[2000005],s[2000005],dp[2000005],sum[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			s[1]=0,dp[1]=1,sum[1]=1,sum[0]=0;
			for(int j=2,l=1,r=1;j<=n;j++){
				if(a[j]-a[j-1]>d) break;
				while(a[l]+d<a[j]) l++;
				r=max(r,l);
				while(r<j-1&&s[r+1]==s[l]) r++;
				s[j]=s[l]+1,dp[j]=sum[r]-sum[l-1],sum[j]=sum[j-1]+dp[j];
				if(dp[j]==2) ans+=n-j+1;
			}
			cout<<ans<<'\n';
			continue;
		}if(c==13||c==14){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=2,j=1,l=1,r=1;i<=n;i++){
				while(a[j]+d<a[i]) j++;
				if(j+1==i) continue;
				while(a[l]+d<a[j]) l++;
				while(a[r]+d<a[j+1]) r++;
				ans+=r-l+1;
			}
			cout<<ans<<'\n';
			continue;
		}
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			s[i]=0,dp[i]=1,sum[i]=1,sum[i-1]=0;
			for(int j=i+1,l=i,r=i;j<=n;j++){
				if(a[j]-a[j-1]>d) break;
				while(a[l]+d<a[j]) l++;
				r=max(r,l);
				while(r<j-1&&s[r+1]==s[l]) r++;
				s[j]=s[l]+1,dp[j]=sum[r]-sum[l-1],sum[j]=sum[j-1]+dp[j];
				if(dp[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

