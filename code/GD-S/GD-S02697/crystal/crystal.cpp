#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m;
map<long long,long long>dp,mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!mp.count(a[i])){
			mp[a[i]]=1;
		}else{
			mp[a[i]]++;
		}
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+i*(a[i]-a[i-1]);
		if(dp[i]>m){
			cout<<i-1+mp[a[i]];
			return 100-100;
		}
	}
	cout<<n;
	return 100-100;
}
