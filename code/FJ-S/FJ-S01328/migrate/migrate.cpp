#include<bits/stdc++.h>
using namespace std;
long long n,d;
const int N=2e6+15;
long long x[N];
pair<long long,long long> dp[N];
//对了，但是tle 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dp[j]={LLONG_MAX-INT_MAX,0};
			dp[i]={0,1};
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(x[k]-x[j]>d) break;
					//cout<<"k:"<<k<<" "<<(dp[k].first>dp[j].first+1)<<endl;
					if(dp[k].first>dp[j].first+1) dp[k]={dp[j].first+1,dp[j].second};
					else if(dp[k].first==dp[j].first+1) dp[k]={dp[j].first+1,dp[k].second+dp[j].second};
				}
				if(dp[j].second==2) sum++;
				//cout<<j<<" "<<dp[j].first<<" "<<dp[j].second<<endl;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	//i'll be killed.
	//Mirage
	//asdfjkl;lkjfdsasdfjkl;lkjfdassdfjkl;lkjfdsasdfjkl;lkjfdsasdfjkl;lkjfdsasdfjkl;lkjfdsasdfjkl;lkjfdsa
	/*
	    _ _ _ _
	     _ _ _
	    _ _ _ _
	     _ _ _
	    _ _ _ _
	     _ _ _
	    _ _ _ _
	     _ _ _
	    _ _ _ _
	     _ _ _
	    _ _ _ _
	    
	*/
	return 0;
}
