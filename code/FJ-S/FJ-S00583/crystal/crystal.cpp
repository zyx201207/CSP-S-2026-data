#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],c[500005];
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long sum=0,ans=0;
	long long l=1,r=1;
	for(r=2;r<=n;r++){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);		
	}
	cout<<ans;
	return 0;
}
