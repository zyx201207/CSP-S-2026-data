#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,cnt;
struct st{
	int a;
	char c;
};
vector<st>dp;
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ox=2;
    for(int i=1;i<=n;i++){
    	int ai;
		char ci;
    	cin>>ai>>ci;
		cnt+=ai;
		if(i>=2&&dp[i-ox].c==ci){
			dp[i-ox].a+=ai; 
			ox++;
		}else{
			dp.push_back({ai,ci});
		}
	} 
	if(cnt%2==1){
		int len=dp.size()/2-1;
		int li=dp.size();
		for(int i=0;i<=len;i++){
			if(dp[li-i-1].c!=dp[i].c){
				int o=min(dp[li-i-1].a,dp[i].a);
				ans+=o;
				dp[li-i-1].a-=o;
				dp[i].a-=o;
			}
			if(dp[li-i-1].a>0){
				int xia=i+1;
				while(dp[li-i-1].a&&xia<len){
					int su=min(dp[li-i-1].a,dp[xia].a);
					dp[xia].a-=su;
					dp[li-i-1].a-=su;
					ans+=su;
					xia++;
				}
			}else{
				int xia=li-2;
				while(dp[i].a&&xia>len){
					int su=min(dp[i].a,dp[xia].a);
					dp[i].a-=su;
					dp[xia].a-=su;
					ans+=su;
					xia--;
				}
			}
		}
	}else{
		int len=dp.size()/2-1,li=dp.size()/2;
		for(int i=0;i<=len;i++){
			if(dp[i+li+1].c!=dp[i].c){
				int o=min(dp[li+i].a,dp[i].a);
				ans+=o;
				dp[li+i+1].a-=o;
				dp[i].a-=o;
			}
			if(dp[li+i+1].a>0){
				int xia=i+1;
				while(dp[li+i+1].a&&xia<=len){
					int su=min(dp[li+i+1].a,dp[xia].a);
					dp[xia].a-=su;
					dp[li+i+1].a-=su;
					ans+=su;
					xia++;
				}
			}else{
				int xia=dp.size()-2;
				while(dp[i].a&&xia>len){
					int su=min(dp[i].a,dp[xia].a);
					dp[i].a-=su;
					dp[xia].a-=su;
					ans+=su;
					xia--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*

*/
