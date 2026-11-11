#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005]={};
int dp[2000005]={};
int cs_in_duilie[2000005]={};
deque<int> duilie;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=0;
	scanf("%lld%lld",&T,&T);
	while(T--){
		int n=0,limit=0;
		scanf("%lld%lld",&n,&limit);
		int cha=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i>1){
				if(!cha) cha=a[i]-a[i-1];
				else if(cha>0&&a[i]-a[i-1]!=cha) cha=-1;
			}
		}
		if(cha>0){
			if(limit<=cha) printf("0\n");
			else printf("%lld\n",max(0LL,n-(limit/cha*2-1)));
			continue;
		}
		int sum=0;
		for(int I=1;I<=n;I++){
			dp[I]=0;
			duilie.push_back(I);
			cs_in_duilie[0]=1;
			for(int i=I+1;i<=n;i++){
				while(!duilie.empty()&&a[i]-a[duilie.front()]>limit){
					cs_in_duilie[dp[duilie.front()]]--;
					duilie.pop_front();
				}
				if(duilie.empty()) break;
				dp[i]=dp[duilie.front()]+1;
				if(cs_in_duilie[dp[duilie.front()]]==2){
					sum++;
				}
				while(!duilie.empty()&&dp[duilie.back()]>dp[i]){
					cs_in_duilie[dp[duilie.back()]]--;
					duilie.pop_back();
				}
				duilie.push_back(i);
				cs_in_duilie[dp[i]]++;
			}
			while(!duilie.empty()){
				cs_in_duilie[dp[duilie.back()]]=0;
				duilie.pop_back();
			}
		}
		printf("%lld\n",sum);
	}
}
/*
0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/
