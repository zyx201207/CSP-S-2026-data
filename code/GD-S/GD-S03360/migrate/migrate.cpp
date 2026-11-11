#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,x[2000005];
int solve(int s,int t){
	if(s==t)return 0;
	int l=s+1,r=0,tot=0;
	while(l+1<=t&&x[l+1]-x[s]<=d)l++;
	while(l+1<=t&&x[l+1]-x[l-1]>d)l++;
	if(l==t)return 0;
	r=l;
	if(x[l+1]-x[l-1]<=d&&(l==s+1||x[l+1]-x[l-2]>d)){
		r++;
		while(r+1<=t&&x[r+1]-x[r-1]>d)r++;
	}
	for(int i=s;i<=t;i++){
		tot+=(r-l);
		while(l+1<=t&&x[l+1]-x[i+1]<=d)l++;
		while(l+1<=t&&x[l+1]-x[l-1]>d)l++;
		if(l==t)return tot;
		if(l>=r){
			r=l;
			if(x[l+1]-x[l-1]<=d&&(l==s+1||x[l+1]-x[l-2]>d)){
				r++;
				while(r+1<=t&&x[r+1]-x[r-1]>d)r++;
			}
		}
	}
	return tot;
}
int solve2(int s,int t){
	int tot=0;
	for(int l=s;l<=t;l++){
		pair<int,int>dp[1005]={{0,0}};
		dp[l]={0,1};
		for(int r=l+1;r<=t;r++){
			dp[r]={1e18,0};
			for(int i=r-1;i>=l;i--){
				if(x[r]-x[i]<=d){
					if(dp[i].first+1<dp[r].first)dp[r]={dp[i].first+1,dp[i].second};
					else if(dp[i].first+1==dp[r].first)dp[r].second=min(10ll,dp[r].second+dp[i].second);
				}
				else break;
			}
			if(dp[r].second==2)tot++;
		}
	}
	return tot;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;int ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1,s=1;i<=n;i++)
			if(i==n||x[i+1]-x[i]>d){
				if(n>5000)ans+=solve(s,i),s=i+1;
				else ans+=solve2(s,i),s=i+1;
			} 
				
		cout<<ans<<'\n';
	}
	return 0;
}

