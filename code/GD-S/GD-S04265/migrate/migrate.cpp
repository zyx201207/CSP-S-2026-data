#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num,sum;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,l=1,cnt=0;
		scanf("%lld %lld",&n,&d);
		vector<int>a(n+1);
		vector<node>dp(n+1,{1000000000000000000,0});
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dp[1].num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(a[i]-a[j]<=d){
					if(dp[i].num>dp[j].num+1){
						dp[i].num=dp[j].num+1;
						dp[i].sum=1;
					}
					else if(dp[i].num==dp[j].num+1){
						dp[i].sum++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(dp[i].sum==2)cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
} 
