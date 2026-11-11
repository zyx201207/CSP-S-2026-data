#include <bits/stdc++.h>
using namespace std;
long long dp[200005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long arr[200005]={0};
	bool a=0;
	bool b[4]={0,0,0,0};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		dp[i]=arr[i];
		if(arr[i]>4){
			a=1;
		}else{
			b[arr[i]]=1;
		}
	}
	if(m==1){
		long long Max=-1;
		for(int i=1;i<=n;i++){
			Max=max(Max,arr[i]);
		}
		cout<<Max;
		return 0;
	}else if(m==n){
		long long ans=arr[1];
		for(int i=2;i<=n;i++){
			ans=ans&arr[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans=max(ans,arr[i]&arr[j]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool flag[200005]={0};
		for(int k=1;k<m;k++){
			long long f=0,d=0;
			for(int j=1;j<=n;j++){
				if(i!=j&&flag[j]==0){
					if(f<arr[j]&dp[i]){
						f=arr[j]&dp[i];
						d=j;
					}
				}
			}
			dp[i]=f;
			flag[d]=1;
		}
	}
	long long mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(dp[i],mx);
	}
	cout<<mx;
	return 0;
}
