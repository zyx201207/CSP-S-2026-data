#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
//ll b[500005];
ll diff[500005];
ll dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		//b[i]=a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		diff[i]=a[i]-a[i-1];
		if(i>2&&diff[i]!=diff[i-1])flag=0;
	}
	//sort(diff+1,diff+n+1);
	
	
	if(flag){
		ll d=diff[n];
		for(ll i=1,j=1;i<=n;i++,j+=i){
			if(j>(long double)m/d){
				cout<<i<<endl;
				break; 
			}
		}
	}else{
		memset(dp,0x7f,sizeof(dp));	
		dp[1]=0;
		for(int i=n;i>=1;i--){
			for(int j=i-1;j>=1;j--){
				dp[i-j+1]=min(dp[i-j]+a[i]-a[j],dp[i-j+1]);
				if(dp[i-j+1]>m)break;
			}
		}
				for(int i=1;i<=n;i++){
			//cout<<dp[i]<<endl;
		}

		cout<<upper_bound(dp+1,dp+n+1,m)-dp-1;
	}
	//int c=unique(a+1,a+n+1)-a-1;
} 
