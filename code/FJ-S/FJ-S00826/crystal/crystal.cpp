#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],dp[N],ans=INT_MIN;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long k=m;
		for(int j=i-1;j>=1;j--){
			k-=(a[i]-a[j]);
			if(k==0){
				dp[i]=i-j+1;
				break;
			}
			if(k<0){
				dp[i]=i-j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i]);
	cout<<ans;
	return 0;
}
