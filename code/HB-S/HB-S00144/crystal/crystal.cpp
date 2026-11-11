#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,cnt,dp[500005],now,l=1,r=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(r<=n){
		if(m>=(a[r]-a[r-1])*(r-l)){
			m-=(a[r]-a[r-1])*(r-l);
			ans=max(ans,r-l+1);
			r++;
		}
		else{
			m+=a[r-1]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
