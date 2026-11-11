#include<bits/stdc++.h>
#define pll pair<long long,long long>
#define mkp make_pair
using namespace std;
long long c,T,n,d,a[2000010],cnt[2000010];
pll dp[2000010];
void solve1(){
	deque<long long>q;
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		long long ans=0;
		for(int i=1;i<=n;i++){
//			cout<<"kkkkkkkkkkkkkk"<<i<<endl;
			dp[i]=mkp(0,1),cnt[0]=1,q.push_back(i);
			for(int j=i+1;j<=n;j++){
				while(!q.empty()){
					if(a[j]-a[q.front()]<=d)break;
					cnt[dp[q.front()].first]-=dp[q.front()].second;
					q.pop_front();
				}
				if(q.empty())break;
				dp[j]=mkp(dp[q.front()].first+1,cnt[dp[q.front()].first]);
				while(!q.empty()){
					if(dp[q.back()].first<=dp[j].first)break;
					cnt[dp[q.back()].first]-=dp[q.back()].second;
					q.pop_back();
				}
				q.push_back(j),cnt[dp[j].first]+=dp[j].second;
				if(dp[j].second==2)ans++;
			}
			while(!q.empty())cnt[dp[q.front()].first]-=dp[q.front()].second,q.pop_front();
		}
		printf("%lld\n",ans);
	}
}
void solve2(){
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		if(n<=2){printf("0\n");continue;}
		long long l=d/(a[2]-a[1]);
		if(l<=1){printf("0\n");continue;}
		if(n-2*l+1>0)printf("%lld\n",n-2*l+1);
		else printf("0\n");
	}
}
//void solve3(){
//	while(T--){
//		scanf("%lld%lld",&n,&d);
//		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
//		long long p;
//		for(int i=1;i<=n;i++)
//			if(a[i]-a[1]<=d&&a[n]-a[i]<=d)p=i;
//		for(int i=1;i<=p;i++){
//			long long l=
//		}
//	}
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if(c<=10){solve1();}
	if(11<=c&&c<=12){solve2();}
//	if(13<=c&&c<=14){solve3();}
	return 0;
}
