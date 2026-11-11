#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define ll long long
ll n,m,a[500005],ans=-1000000005,sum[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int j=1;j<=n;j++){
//		cout<<a[j]<<" ";
//	}
	for(int i=1;i<=n;i++){
		if(i>1) swap(a[i],a[1]);
		for(int j=1;j<=n;j++){
			//cout<<a[j]<<" "<<a[1]<<endl;
			sum[j]=a[j]-a[1];
		}
//		for(int j=1;j<=n;j++){
//			cout<<sum[j]<<" ";
//		}
//		cout<<endl;
		sort(sum+1,sum+n+1);
		
		ll cnt=0;
		ll temp=m;
		int pos=upper_bound(sum+1,sum+n+1,0)-sum-1;
		//cout<<pos<<endl;
		for(int j=pos;j>=1;j--){
			//cout<<j<<endl;
			if(sum[j]<=0){
				if(temp+sum[j]>=0){
					//cout<<sum[j]<<endl;
					cnt++;
					temp+=sum[j];
					//cout<<m<<endl;
				}
			}
		}
		ans=max(ans,cnt);
		//cout<<"ans"<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
