#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
vector<long long>v,s,dp(100005,1);
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	int tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		long long t;cin>>t;
		v.push_back(t);
	}sort(v.begin(),v.end());
	for(int i=1;i<n;i++){
		s.push_back(v[i]-v[i-1]);
	}for(int i=0;i<n;i++){
		long long x=m;
		for(int j=i;j<n-1;j++){
			if(x-s[j]*dp[i]>=0){
				x-=s[j]*dp[i];
			    dp[i]++;
			    ans=max(ans,dp[i]);
			}
			else break;
		}
	}cout<<ans;
	return 0;
}
