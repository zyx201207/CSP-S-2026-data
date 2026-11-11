#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000001],dp[1000001],maxx=-1e18;
bool bol=false,txi=true,txd=true;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]<a[i-1]){
			bol=true;
		}
		else if(txd&&i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			txd=false;
		}
		else if(txi&&a[i]!=i){
			txi=false;
		}
	}
	if(txd){
		long long jg=a[2]-a[1],ans=0,num=0,mq;
		mq=jg;
		while(m>num){
			num+=mq;
			mq+=jg;
			if(num<=m){
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	if(txi){
		long long ans=0,num=0,jg=1;
		while(m>num){
			num+=jg;
			jg++;
			if(m>num){
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans+1;
		return 0;
	}
	if(bol){
		sort(a+1,a+n+1);
	}
	for(int i=1;i<=n;i++){
		long long num=m,ans=0;
		for(int j=i-1;j>=1;j--){
			if(num>=(a[i]-a[j])){
				num-=(a[i]-a[j]);
				ans++;
			}
			else{
				break;
			}
		}
		dp[i]=ans+1;
	}
	for(int i=1;i<=n;i++){
		maxx=max(maxx,dp[i]);
	}
	cout<<maxx;
	return 0;
}
