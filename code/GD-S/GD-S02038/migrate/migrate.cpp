#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
const longlong int_max=0x3f3f3f3f3f3f3f3fll;
longlong c,_,n,d,ans,x[2000010ll];
longlong check(longlong a){
	vector < longlong > dp(n+10ll,0ll),minn(n+10ll,int_max);
	dp[a]=1ll,minn[a]=0ll;
	queue < longlong > que;
	que.push(a);
	longlong ans=0ll;
	while(not(que.empty())){
		longlong now=que.front();
		que.pop();
		for(longlong i=now+1ll;i<=n and x[i]<=x[now]+d;i++){
			if(minn[now]+1ll<=minn[i]){
				if(minn[now]+1ll<minn[i])	que.push(i);
				minn[i]=minn[now]+1ll;
				dp[i]+=dp[now];
			}
		}
	}
	for(longlong i=a;i<=n;i++){
//		printf("%lld:%lld,%lld ",i,dp[i],minn[i]);
		if(a<i and dp[i]==2ll)	ans++;
	}
//	printf("    cnt:%lld\n",ans);
	return ans;
}
signed main(){
	NOTLE::NO_TLE();//samples:{1,2,3}
	freopen("migrate.in","r",stdin),frein=true;
	freopen("migrate.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%lld%lld",&c,&_);
	if(refrein)	printf("%lld %lld\n",c,_);
	while(_--){
		ans=0ll;
		scanf("%lld%lld",&n,&d);
		if(refrein)	printf("%lld %lld\n",n,d);
		for(longlong i=1ll;i<=n;i++){
			scanf("%lld",&x[i]);
			if(refrein)	printf("%lld ",x[i]);
		}
		sort(x+1ll,x+1ll+n);
		if(refrein)	printf("\n");
		for(longlong i=1ll;i<n;i++){
			ans+=check(i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
