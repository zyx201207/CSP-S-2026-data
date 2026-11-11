//GZ-S00054 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000005];
ll dp[2000005];
ll len[2000005];
int check(ll s){
	ll l,r;
	while(l<r){
		ll mid=(l+r)/2+1;
		if(x[mid]==s){
			return mid;
		}
		else{
			if(x[mid]<s){
				r=mid-1;
			}
			else{
				l=mid;
			}
		}
	}
	return 0;
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(dp,n,0);
		memset(len,n,0);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		} 
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			ll sum=0;
			ll minn=1e18;
			for(int j=d;j>=1;j--){
				if(check(x[i]-j)){
					minn=min(minn,len[check(x[i]-j)]+1);
				}
			}
			ll times=0;
			for(int j=d;j>=1;j--){
				if(check(x[i]-j)){
					if(len[check(x[i]-j)]+1==minn){
						times++;
					}
				}
			}
			if(times==2){
				dp[i]++;
			}
			len[i]=minn;
		}
		cout<<dp[n]<<endl;
	}
	
	return 0;
}
