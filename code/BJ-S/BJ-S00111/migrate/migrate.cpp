#include<bits/stdc++.h>
using namespace std;
int c,t,n,dp[2000005];
long long d,a[2000005];
map<long long,int>mp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		int q=3+2*(d-2);
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]=i;
		}/*
		for(int i=1;i+3<=n;i++){
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d)ans++;
		}*/
		
		for(int i=1;i<=n;i++){
			if(mp[a[i]+q]!=0&&mp[a[i]+q]-mp[a[i]]!=1
			&&mp[a[i]+d]!=0&&mp[a[i]+d-1]!=0)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
