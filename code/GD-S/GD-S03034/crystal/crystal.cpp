#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cha[500005],suo[500005],now,dp[500005],ans,to[500005],cnt[500005],mp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
		dp[i]=1;
		mp[i]=m;
	}
	sort(a,a+n);
	for(int i=1;i<n;++i){
		cha[i]=a[i]-a[i-1];
		suo[i]=cha[i];
	}
	sort(suo+1,suo+n);
	for(int i=1;i<n;++i){
		now=lower_bound(suo+1,suo+n,cha[i])-suo;
		to[now+cnt[now]]=i;
		++cnt[now];
	}
	for(int i=1;i<n;++i){
		now=to[i];
		if(cha[now]==0){
			dp[now]+=dp[now-1];
			dp[now-1]=dp[now];
			ans=max(ans,dp[now]);
			
		}
		else if(mp[now-1]-dp[now-1]*cha[now]>=0){
			mp[now]=mp[now-1]-dp[now-1]*cha[now];
			dp[now]+=dp[now-1];
			ans=max(ans,dp[now]);
		}
		else{
			dp[now]+=mp[now-1]/cha[now];
			ans=max(ans,dp[now]);
			mp[now]=mp[now-1]-mp[now-1]/cha[now];
		}
	}
	printf("%lld",ans);
	return 0;
}

