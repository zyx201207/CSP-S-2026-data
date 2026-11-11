#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i=n;i<=m;i++)
#define ll long long
#define int long long
const int N=2e6+10;
int c,t,n,d,a[N],q[N];//min dis  ways
ll ans,dp[N],ways[N],tmp[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		rep(i,1,n)cin>>a[i];
		if(c==11||c==12||n>=5001){
			ans=0;
			int st=1;
			dp[st]=0;
			ways[st]=1;
			int fir=1,last=1;
			q[fir]=st;
		rep(i,st+1,n){
			while(fir<=last&&a[i]-a[q[fir]]>d){
				fir++;
			}
			if(fir>last)break;
			dp[i]=dp[q[fir]]+1;
			while(fir<=last&&dp[i]<dp[last]){
				last--;
			}
			if(fir>last)break;
			q[++last]=i;
			rep(p,fir,last){
				if(dp[q[fir]]!=dp[q[p]])break;
				ways[i]+=ways[q[p]];
			}
			ways[i]=max(ways[i],(ll)1);
			//cout<<i<<' '<<dp[i]<<' '<<ways[i]<<'\n';
			if(ways[i]==2)tmp[i]=1;
		}
		rep(i,2,n){
			ans+=tmp[i]*(n-i+1);
		}
		cout<<ans<<'\n';
		rep(i,0,n)tmp[i]=q[i]=dp[i]=ways[i]=0;
		}else{
		rep(st,1,n-1){
rep(i,0,5001)q[i]=dp[i]=ways[i]=0;
		    dp[st]=0;
			ways[st]=1;
			int fir=1,last=1;
			q[fir]=st;
		rep(i,st+1,n){
			while(fir<=last&&a[i]-a[q[fir]]>d){
				fir++;
			}
			if(fir>last)break;
			dp[i]=dp[q[fir]]+1;
			while(fir<=last&&dp[i]<dp[last]){
				last--;
			}
			if(fir>last)break;
			q[++last]=i;
			rep(p,fir,last){
				if(dp[q[fir]]!=dp[q[p]])break;
				ways[i]+=ways[q[p]];
			}
			ways[i]=max(ways[i],(ll)1);
			//cout<<i<<' '<<dp[i]<<' '<<ways[i]<<'\n';
			if(ways[i]==2)ans++;
		}
	}
	cout<<ans<<'\n';
}
	}
	return 0;
}

